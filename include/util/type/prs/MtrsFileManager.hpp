#ifndef MTRS_FILE_MANAGER_HPP
#define MTRS_FILE_MANAGER_HPP

#include "DeferredData.hpp"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

#include <chrono>

namespace mtrs::prs
{

class MtrsFileManager
{
public:
    struct MtrsFile
    {
        uint64_t data_size;
        const uint64_t chach_lifetime;

        std::vector<char> data;
        std::unordered_map<uint64_t, DeferredData> deferred_data;
        double current_lifetime;
        bool dirty = false;
    };

private:
    uint64_t _limit_size_cache;
    uint64_t _current_size_cache;

    std::unordered_map<std::string, MtrsFile> _files;
    std::vector<decltype(_files)::iterator> _file_iterators;

    MtrsFile create_file_to_path(const std::string &path);
    void read_file(const std::string &path, MtrsFile &file);
    void clear_file(const std::string &path, MtrsFile &file);

public:
    MtrsFileManager(std::unordered_set<std::string> paths, const uint64_t limit_size_cache);

    MtrsFileManager() = delete;
    MtrsFileManager(const MtrsFileManager &) = delete;
    MtrsFileManager &operator=(const MtrsFileManager &) = delete;
    MtrsFileManager(MtrsFileManager &&other);
    MtrsFileManager &operator=(MtrsFileManager &&other);
    ~MtrsFileManager();

    MtrsFile *get_file(const std::string &path);

    void update(const double &delta);
    void clear();
};

}

#endif

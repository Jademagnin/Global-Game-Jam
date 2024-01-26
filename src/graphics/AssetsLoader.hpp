/*
** EPITECH PROJECT, 2024
** GGJ
** File description:
** AssetsLoader
*/

#ifndef ASSETS_LOADER_H_
#define ASSETS_LOADER_H_

#include <unordered_map>
#include <vector>
#include <set>

#include <string>
#include <string_view>
#include <regex>

#include <algorithm>
#include <functional>
#include <filesystem>

namespace fs = std::filesystem;

namespace Loader {

template<typename T>
class AssetsLoader {
 public:
  AssetsLoader() = default;
  ~AssetsLoader() = default;

  AssetsLoader(const AssetsLoader<T> &other) = delete;
  AssetsLoader &operator=(const AssetsLoader<T> &other) = delete;

  AssetsLoader(const AssetsLoader<T> &&other) = delete;
  AssetsLoader &operator=(const AssetsLoader<T> &&other) = delete;

  void setSupportedFormats(std::string formats, std::string delim);

  bool loadAssets(std::string_view folderPath,
                  std::function<void(T &item, const fs::path &itemPath)> loader);

  T *operator[](std::string_view name);
  T *getPtr(std::string name);
  const T *getPtr(const std::string_view name) const;

 private:
  std::set<std::string> m_supportedFormats;
  std::unordered_map<std::string, T> m_storage;

  bool exists(const fs::path &p, fs::file_status s = fs::file_status{});
};
}

#endif
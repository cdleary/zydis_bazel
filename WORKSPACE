workspace(name = "zydis_bazel")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
  name = "zydis",
  commit = "e79c7d0ab3046511c25f940ec0d8933af09ba4e1",
  shallow_since = "1585555482 +0200",
  remote = "https://github.com/zyantific/zydis.git",
  init_submodules = 1,
  build_file_content = """
cc_library(
  name = "zydis",
  srcs = glob([
    "src/**/*.c",
    "src/Generated/*.inc",
    "include/Zydis/Internal/*.h",
    "include/Zydis/Generated/*.h",
    "dependencies/zycore/include/Zycore/**/*.h",
    "dependencies/zycore/**/*.c",
  ]),
  hdrs = glob([
    "include/Zydis/*.h",
  ]) + [
  ],
  copts = [
    "-Iexternal/zydis/src",
  ],
  includes = [
    "include",
    "dependencies/zycore/include",
  ],
  deps = [
    "@//third_party/zydis:config_headers",
  ],
  visibility = ["//visibility:public"],
)

cc_binary(
    name = "ZydisDisasm",
    srcs = ["tools/ZydisDisasm.c"],
    deps = [
        ":zydis",
    ],
)

cc_binary(
    name = "ZydisInfo",
    srcs = ["tools/ZydisInfo.c"],
    deps = [
        ":zydis",
    ],
)
"""
)

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/c512f118dde6ffd51cb7d8ac8804bbaf4d266c3a.zip"],
  strip_prefix = "abseil-cpp-c512f118dde6ffd51cb7d8ac8804bbaf4d266c3a",
  sha256 = "8400c511d64eb4d26f92c5ec72535ebd0f843067515244e8b50817b0786427f9",
)


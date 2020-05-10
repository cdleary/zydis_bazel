cc_binary(
    name = "sample",
    srcs = ["sample.cc"],
    deps = [
        "@zydis//:zydis",
    ],
)

cc_binary(
    name = "lines_to_lengths",
    srcs = ["lines_to_lengths.cc"],
    deps = [
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:str_format",
        "@zydis//:zydis",
    ],
)

py_test(
    name = "lines_to_lengths_test",
    srcs = ["lines_to_lengths_test.py"],
    data = [
        ":lines_to_lengths",
    ],
    deps = [
        "@bazel_tools//tools/python/runfiles"
    ],
)

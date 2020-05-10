#include <iostream>

#include "absl/strings/numbers.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"
#include "include/Zydis/Zydis.h"

int main() {
  ZydisDecoder decoder;
  ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64,
                   ZYDIS_ADDRESS_WIDTH_64);

  ZydisDecodedInstruction instruction;
  std::string line;
  std::vector<uint8_t> bytes;
  int64_t lines = 0;

  while (true) {
    if (!std::cin.good()) {
      break;
    }
    getline(std::cin, line);

    std::vector<absl::string_view> pieces = absl::StrSplit(line, " ");
    bytes.clear();
    lines++;
    for (absl::string_view piece : pieces) {
      uint32_t value;
      if (!absl::numbers_internal::safe_strtoi_base(piece, &value, 16) ||
          (value & 0xff) != value) {
        std::cerr << absl::StreamFormat(
            "Could not decode value as byte: \"%s\"; line: \"%s\"\n", piece,
            line);
        return EXIT_FAILURE;
      }
      bytes.push_back(value);
    }

    ZydisDecoderDecodeBuffer(&decoder, bytes.data(), bytes.size(),
                             &instruction);
    std::cout << absl::StreamFormat("%d\n", instruction.length);
  }
  std::cerr << absl::StreamFormat("Processed %d lines\n", lines);
  return EXIT_SUCCESS;
}

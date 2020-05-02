// Minimal example for instruction formatting, based on
// https://github.com/zyantific/zydis/blob/master/README.md

#include "include/Zydis/Zydis.h"

#include <iostream>
#include <vector>

int main() {
  std::vector<uint8_t> data = {0x41, 0xff, 0x14, 0xdf};

  ZydisDecoder decoder;
  ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64,
                   ZYDIS_ADDRESS_WIDTH_64);

  ZydisFormatter formatter;
  ZydisFormatterInit(&formatter, ZYDIS_FORMATTER_STYLE_INTEL);

  const ZyanUSize length = data.size();
  ZydisDecodedInstruction instruction;
  ZydisDecoderDecodeBuffer(&decoder, data.data(), length, &instruction);

  char buffer[256];
  ZydisFormatterFormatInstruction(&formatter, &instruction, buffer,
                                  sizeof(buffer), 0);
  std::cout << buffer << std::endl;
  return EXIT_SUCCESS;
}

#include "cpus.h"
#include <string>
#include <unistd.h>

// TODO - CLI
// enable-rules option
// disable-rules option
// enable-cores option
// disable-cores option



int main() {
  std::string action;
  // TODO - Have CLI assign action
  cpus::CPU* processor = cpus::DetectCPU();

  // Enable/Disable P-Cores
  if (action == "enable-cores") {
    processor.SetPCores(true);
  }
  else if (action == "disable-cores") {
    processor.SetPCores(false);
  }

  // Enable/Disable Udev Rules
  else if (action == "enable-rules") {
    // TODO - Enable udev rules
  }
  else if (action == "disable-rules") {
    // TODO - Disable udev rules
  }
}

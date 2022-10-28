#include "includes/cpus.h"
#include "includes/data_utils.h"
#include <list>
#include <map>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace cpus {

// class NonExistentCoreError
// Constructor for NonExistentCoreError Exception
NonExistentCoreError::NonExistentCoreError(int core){
  std::string message = "NonExistentCoreError: Core" + std::to_string(core) + " does not exist.";
  // Save the message as char* instead of std::string.
  this->message = const_cast<char*>(message.c_str()); 
}

// Get the message from the NonExistentCoreError Exception
char* NonExistentCoreError::what(){
  return this->message;
}


// class CPU
// Constructor for CPU class.
CPU::CPU(std::string model_name, std::list<int> p_cores, std::list<int> e_cores) {
  this->model_name = model_name;
  this->short_model = data_utils::StringSplit(this->model_name, " ").back();
  this->p_cores = p_cores;
  this->e_cores = e_cores;
}

// Private method of CPU class.
void CPU::SetCore(int core, bool status) {
  // Don't take core 0 offline or you'll crash the system.
  if (core != 0) {
    // Open the core file.
    std::string file_path = "/sys/devices/system/cpu/cpu" + std::to_string(core) + "/online";
    std::ofstream core_file(file_path);
    if (core_file.is_open()) {
      // Write the status to the core file.
      std::string core_file_value;
      if (status == true) {
        core_file << "1";
      }
      else {
        core_file << "0";
      }
      // Write and close the core file.
      core_file.flush();
      core_file.close();
    }
    // Throw NonExistentCoreError if the core does not exist.
    else {
      throw NonExistentCoreError(core);
    }
  }
}

// Public method of CPU class.
void CPU::SetPCores(bool status) {
  std::list<int>::iterator core_iter;
  for (core_iter = this->p_cores.begin(); core_iter != this->p_cores.end(); core_iter++) {
    this->SetCore(*core_iter, status);
  }
}

// Public Function
CPU* DetectCPU() {
  // CPU objects for each CPU.
  CPU i7_1260p = CPU("12th Gen Intel(R) Core(TM) i7-1260P", {}, {});
  // Map of Model Names and pointers to the above CPU objects.
  std::map<std::string, CPU*> supported_cpus = {
    {"12th Gen Intel(R) Core(TM) i7-1260P", &i7_1260p}
  };

  // Load model name value from cpuinfo.
  std::vector<std::string> model_name_line = data_utils::StringSplit(data_utils::FindLine("/proc/cpuinfo", "model name"), ": ");
  // Return the CPU object from `supported_cpus` based on the model name.
  CPU* processor = supported_cpus[model_name_line.at(1)];
  return processor;
}
} // namespace cpus

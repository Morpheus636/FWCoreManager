#ifndef FWCOREMANAGER_COREMGR_CPUS_H_
#define FWCOREMANAGER_COREMGR_CPUS_H_

#include <list>
#include <string>

namespace cpus {

// Exception raised when CPU.SetCore() is passed a core number that
// does not exist.
class NonExistentCoreError : public std::exception {
    private:
        char* message;
    public:
        // Constructor
        NonExistentCoreError(int core_number);
        // Returns an explanation of the exception.
        char* what();
};


// Interface for manipulating the CPU. 
class CPU {
    private:
        std::list<int> p_cores;
        std::list<int> e_cores;
        // Enables or disables the CPU core identified by the integer `core`
        // using `/sys/devices/system/cpu`. `status` determines whether the
        // core is enabled (true) or disabled (false). Returns void.
        //
        // Does nothing if `core` is 0, because core 0 cannot be disabled.
        // Throws NonExistentCoreError if the core does not exist.
        void SetCore(int core, bool status);
    public:
		// Constructor.
        CPU(std::string model_name, std::list<int> p_cores, std::list<int> e_cores);
        // Enables or disables all P-Cores. `status` determines whether the
        // cores are enabled (true) or disabled (false). Returns void.
        void SetPCores(bool status);
        std::string model_name;
        std::string short_model;
};

// Uses /proc/cpuinfo to determine the CPU of the system.
// Returns a corresponding instance of the CPU class.
CPU DetectCPU();

} // namespace cpus
#endif

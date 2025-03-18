#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LOG_DIR "logs"
#define LOG_FILE "./logs/drivers.log"

void createLogDir() {
    CreateDirectory(LOG_DIR, NULL);
}

void logMessage(const char *message) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile) {
        fprintf(logFile, "[%s] %s\n", __TIMESTAMP__, message);
        fclose(logFile);
    }
}

int isGitInstalled() {
    return (system("git --version > nul 2>&1") == 0);
    // checking fucking git
    // bro install git wtf
}

void runShellScript(const char *script) {
    char command[512];
    sprintf(command, "C:\\Program Files\\Git\\bin\\bash.exe -c './%s'", script);
    int result = system(command);

    if (result == 0) {
        logMessage("Executed successfully:");
        logMessage(script);
    } else {
        logMessage("ERROR executing:");
        logMessage(script);
    }
}

void runPowerShellScript(const char *script) {
    char command[512];
    sprintf(command, "C:\\Program Files\\Git\\bin\\bash.exe -c 'powershell -ExecutionPolicy Bypass -File ./%s'", script);
    int result = system(command);

    if (result == 0) {
        logMessage("Executed successfully:");
        logMessage(script);
    } else {
        logMessage("ERROR executing:");
        logMessage(script);
    }
}

int main() {
    printf("Starting Windows 10 Gaming Optimizer...\n");
    createLogDir();
    logMessage("=== Starting Optimization Process ===");

    if (!isGitInstalled()) {
        printf("ERROR: Git is not installed. Please install Git first.\n");
        logMessage("ERROR: Git is not installed.");
        return 1;
    }

    printf("Git found! Running optimizations...\n");
    logMessage("Git found! Running optimizations...");

    runShellScript("./boot/check_xmp.sh");
    runShellScript("./boot/disable_hibernation.sh");
    runShellScript("./boot/enable_all_cpu_cores.sh");
    runShellScript("./boot/disable_services_boot.sh");
    runShellScript("./network/tcp_ip_boost.sh");
    runPowerShellScript("./powershell/update_drivers.ps1");

    logMessage("=== Optimization Process Completed ===");
    printf("Optimization completed! Check logs in 'logs/' folder.\n");

    system("pause");
    return 0;
}

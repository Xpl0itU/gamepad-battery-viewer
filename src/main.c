#include <vpad/input.h>

#include <whb/log.h>
#include <whb/log_console.h>
#include <whb/proc.h>

int main() {
    WHBProcInit();
    WHBLogConsoleInit();

    VPADStatus vpadStatus;

    VPADRead(VPAD_CHAN_0, &vpadStatus, 1, NULL);

    WHBLogPrintf("GamePad Battery: %.2f%%", (vpadStatus.battery / 4) * 100.0);

    WHBLogConsoleDraw();

    while (WHBProcIsRunning()) {}

    WHBLogConsoleFree();
    WHBProcShutdown();
    return 0;
}
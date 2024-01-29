#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/usb/IOUSBLib.h>
#include <fmt/format.h>

#if MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_VERSION_12_0
#define kIOMainPortDefault kIOMasterPortDefault
#endif

int main(void) {
    return 0;
}

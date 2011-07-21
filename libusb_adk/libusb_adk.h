
#include <usb.h>
extern int mainPhase();
extern int init(void);
extern int closeHandle(void);
extern int chAccessoryMode(
		const char* manufacturer,
		const char* modelName,
		const char* description,
		const char* version,
		const char* url,
		const char* serialNumber);
extern void print_devs(libusb_device **devs);
extern int open_accesory_dev();
#if defined(__MINGW32__)
#include <windows.h>
#define sleep Sleep
#else
#define sleep sleep
#endif


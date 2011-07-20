#include "libusb_adk.h"

int main (int argc, char *argv[])
{
	if(init() < 0)
		return;
	//doTransfer();
	if(chAccessoryMode(
				"bols",
				"Demo",
				"Description",
				"1.0",
				//"market://search?jp.co.topgate.android.game.gree.sengoku",
				"http://market.android.com/search?q=jp.co.topgate.android.game.gree.sengoku",
				//"http://neuxs-computing.ch",
				"2hhh254711SerialNhho.") < 0){
		fprintf(stdout, "Error setting up accessory\n");
		closeHandle();
		return -1;
	};
	fprintf(stdout, "end setup\n");

	if(mainPhase() < 0){
		fprintf(stdout, "Error during main phase\n");
		closeHandle();
		return -1;
	}	
	closeHandle();
	fprintf(stdout, "Done, no errors\n");
	libusb_close(handle);
	return 0;
}

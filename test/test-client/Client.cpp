#include <iostream>
#include <masesk/EasySocket.hpp>
#include <string>
using namespace std;
using namespace masesk;

int main() {
	
	try
	{
		EasySocket socketManager;
		socketManager.socketConnect("test", "127.0.0.1", 4001);
		string userInput;
		char serverResponse[DEFAULTBUF_LEN];
		while (true) {
			cout << "> ";
			getline(cin, userInput);
			if (userInput.size() <= 0) {
				break;
			}
			socketManager.socketCleanBuffer("test");
			socketManager.socketSendToServer("test", userInput);
			socketManager.socketReceiveResponseFromServer("test", serverResponse);
			std::cout << serverResponse << std::endl;

		}
		socketManager.closeConnection("test");
		return 0;
	}
	catch (socket_error_exception sock_exception)
	{
		std::cout << sock_exception.what() << std::endl;
		while (true);
		return -1;
	}
	
	
}
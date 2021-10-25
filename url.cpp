#include <iostream>
#include <string>
using namespace std;

int main(int s,char* url_arr[]) {
    //puts the string url into an array
    string url = url_arr[1];

    //array of valid protocols
    string protocols[] = {"http","https","ftp","ftps"};
    //looks for the protocol within the url
    string checkProtocols = url.substr(0,url.find("://"));

    //checking protocol validity
    for (int i=0; i<4; i++)
    {
        if(checkProtocols == protocols[i])
        {
            cout << "Protocol: " + checkProtocols << endl;
            break;
        }
        if (i == 3)
        {
            cout << "Protocol: " + checkProtocols + " is not a valid protocol" << endl;
            return 1;
        }
    }
    //URL variable without the protocol
    string urlNoProto = url.substr(url.find("://")+3);
    //domain variable
    string domain = urlNoProto.substr(0, urlNoProto.find('/'));
    //port variable
    int port = stoi(domain.substr(domain.find(':')+1));
    //printing domain
    domain = domain.substr(0, domain.find(':'));
    cout << "Domain: " + domain << endl;

    //checking for port validity
    if (port >1 && port < 65535)
    {
        cout << "Port: " << port << endl;
    }
    else
    {
        cout << "Port: port number must be between 1 and 65535" << endl;
    }

    //filepath
    string afterDom = urlNoProto.substr(urlNoProto.find('/')+1);
    string filePath = afterDom.substr(0, afterDom.find('?'));
    cout << "File Path: " << filePath << endl;

    //parameters
    string param = afterDom.substr(afterDom.find('?')+1);
    cout << "Parameters: " << param <<endl;

    return 0;
}

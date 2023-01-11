#include <bits/stdc++.h>
using namespace std;

string convIDtoURL(int n) {

    char alphaMap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
        "ghijklmnopqrstuvwxyz0123456789";

  string url;

  while (n > 0) { 
   
    url.push_back(alphaMap[n%62]);
    n /= 62;
  }

  reverse(url.begin(), url.end());

  return url;
}

int convURLtoID(string shortURL) {
  int urlID = 0; 

  for (int i=0; i < shortURL.length(); i++) {
   
     if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
        urlID = urlID*62 + shortURL[i] - 'A';

     
     if ('a' <= shortURL[i] && shortURL[i] <= 'z')
        urlID = urlID*62 + shortURL[i] - 'a' + 26;
    
    
     if ('0' <= shortURL[i] && shortURL[i] <= '9')
        urlID = urlID*62 + shortURL[i] - '0' + 52;
  }

  return urlID;
}

int main() {

    int n = 12345;
    string url = convIDtoURL(n);
    cout << "Generated short url is here www.urlShortner.com/" << url << endl;
    cout << "ID from URL is " << convURLtoID(url);
  
    return 0;
}

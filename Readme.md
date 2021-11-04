# RiotKiller

Wtf Riot? Anyways...

This application launch League of Legends by calling `RiotClientServices.exe --launch-product=league_of_legends --launch-patchline=live`. It seems to be the modern way to launch League of Legends.

I've tried opening LeagueClient.exe without using RiotClientServices but it keeps opening the RiotClient no matter what. So it doesn't matter.

If you have installed the Riot Client in the default folder `C:\Riot Games\Riot Client`, this will work! 

Otherwise, I didn't make this application to accept custom paths. If someone can throw me some code, I will merge it up and update it.

## Download

Version v1.0 is here. [Download it](https://github.com/Arecsu/RiotKiller/releases/download/v1.0/RiotKiller.exe).

## How it works

1. Open RiotKiller.exe It will automatically launch League of Legends for you
2. Once League of Legends has been launched, it sits there. You can minimize the console window.
3. It will detect when you close the client.
4. Once the client is closed, it will force kill LeagueClient.exe and RiotClientServices.exe
5. Done! It will now automatically close by itself.

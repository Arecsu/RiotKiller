# RiotKiller

Wtf Riot? Anyways...

This application launches League of Legends by calling `RiotClientServices.exe --launch-product=league_of_legends --launch-patchline=live`. It seems to be the modern way to launch League of Legends.

I've tried opening LeagueClient.exe without using RiotClientServices but it keeps opening the RiotClient no matter what. So it doesn't matter.

If you have installed the Riot Client in the default folder `C:\Riot Games\Riot Client`, this will work! 

Otherwise, I didn't make this application to accept custom paths. If someone can throw me some code, I will merge it up and update it.

## Download

Version v1.0 is here. 

[With console messages](https://github.com/Arecsu/RiotKiller/releases/download/v1.0/RiotKiller.exe)

[Without messages (invisible mode RECOMMENDED)](https://github.com/Arecsu/RiotKiller/releases/download/v1.0/RiotKiller-invisible.exe)

## How it works

1. Open RiotKiller.exe It will automatically launch League of Legends for you
2. Once League of Legends has been launched, it will keep monitoring the process. You can minimize the console window.
3. It will detect when you close the client.
4. Once the client is closed, it will force kill LeagueClient.exe and RiotClientServices.exe
5. Done! It will now automatically close by itself.

## The community so far:

- https://www.reddit.com/r/leagueoflegends/comments/qlnmmc/i_dont_care_if_league_gives_me_another_client_to/
- [Whoops, this one has been deleted!](https://www.reddit.com/r/leagueoflegends/comments/qmgrlz/the_state_of_this_new_launcher_is_not_ok/). They say it's because is a repost from the previous one... but they cover sightly different points of view about the issue. Mmmmm...
- And [my post](https://www.reddit.com/r/leagueoflegends/comments/qmqk6v/tired_of_riot_client_opening_after_closing_league/) about this tool, which 10 minutes after being posted has been deleted. Thank you Riot. No reasons why it has been removed so far.

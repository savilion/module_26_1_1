#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "player.h"
#include "tracklist.h"


int main()
{
    std::srand(std::time(nullptr));
    auto* trackList = new TrackList();
    auto* player = new Player();

    for (int i = 0; i < 5; ++i)
    {
        std::string name = "Track#" + std::to_string(i);
        std::time_t now = std::time(nullptr);
        int duration = rand()%85 + 100;

        trackList->setTrackList(name, now, duration);
    }

    player->setCopyTrackToPlayer(trackList->getNameTrack());

    while (true)
    {
        std::string answer;
        std::cout << R"(Enter "play" to start/resume playback, "next" next track, "stop" to stop, "exit" to exit)" << std::endl;
        std::cout << "-> ";
        std::cin >> answer;

        if (answer == "play")
        {
            int num;
            if (player->getPlayback() && !player->getPause())
            {
                std::cout << "<-\tThe track is already playing." << std::endl;
            }
            else if (player->getPlayback() && player->getPause())
            {
                std::cout << "<-\tResume playback." << std::endl;
            }
            else
            {
                Player::showTrackList(player);
                std::cout << "<-\tEnter the track number: ";
                std::cin >> num;
                while (num < 0 || num > trackList->numberTrack())
                {
                    std::cout << "<-\tThere is no such track! Try again." << std::endl;
                    Player::showTrackList(player);
                    std::cout << "<-\tEnter the track number: ";
                    std::cin >> num;
                }
                player->trackPlay(num);
                TrackList::showTrackInfo(trackList,num);
            }
        }
        else if (answer == "pause")
        {
            if (!player->getPlayback()) std::cout << "<-\tNothing is being played" << std::endl;
            else if (!player->getPause())
            {
                player->trackPause();
            }
        }
        else if (answer == "next")
        {
            int nextTrack = rand()%trackList->numberTrack();
            player->setKeyStop();
            player->trackPlay(nextTrack);
            TrackList::showTrackInfo(trackList,nextTrack);
        }
        else if (answer == "stop")
        {
            if (player->getPlayback())
            {
                player->setKeyStop();
                std::cout << "<-\tPlayback stopped." << std::endl;
            }
        }
        else if (answer == "exit") break;
    }

    delete trackList;
    delete player;
    trackList = nullptr;
    player = nullptr;
    return 0;
}

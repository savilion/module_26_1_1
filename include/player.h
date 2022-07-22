#pragma once

class Player
{
    bool playbackKey = false;
    bool pauseKey = false;
    int currentTrack;
    std::vector<std::string> nameTrack;
public:
    void setCopyTrackToPlayer(const std::vector<std::string>& vec)
    {
        if (vec.empty())
        {
            std::cerr << "<-\tTracks not loaded!" << std::endl;
        }
        else nameTrack.assign(vec.begin(), vec.end());
    }
    static void showTrackList(Player* player)
    {
        for (int i = 0; i < player->nameTrack.size(); ++i)
        {
            std::cout << i << ". " << player->nameTrack[i] << std::endl;
        }
    }
    void trackPlay(int value)
    {
        if (!playbackKey)
        {
            playbackKey = true;
            currentTrack = value;
            std::cout << "<-\tPlay " << value << " track" << std::endl;
        }
    }
    void trackPause()
    {
        if (!pauseKey)
        {
            pauseKey = true;
            std::cout << "<-\tTrack " << currentTrack << " is pause." << std::endl;
        }
        else if (playbackKey)
        {
            pauseKey = false;
        }
    }
    bool getPlayback()
    {
        return playbackKey;
    }
    bool getPause()
    {
        return pauseKey;
    }
    void setKeyStop()
    {
        playbackKey = false;
        pauseKey = false;
    }
};

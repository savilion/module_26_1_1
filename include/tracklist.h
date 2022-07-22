#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

class TrackList
{
    std::vector<std::string> nameTrack;
    std::vector<std::time_t> dateCreatedTrack;
    std::vector<int> durationTrack;
public:
    void setTrackList(std::string& name, std::time_t& date, int& duration)
    {
        nameTrack.push_back(name);
        dateCreatedTrack.push_back(date);
        durationTrack.push_back(duration);
    }

    std::vector<std::string> getNameTrack()
    {
        return nameTrack;
    }

    int numberTrack()
    {
        return nameTrack.size();
    }

    static void showTrackInfo(TrackList* trackList, int value)
    {
        std::tm* local = std::localtime(&trackList->dateCreatedTrack[value]);
        std::cout << "Track info: " << std::endl;
        std::cout << "Track name: " << trackList->nameTrack[value] << ". Date created: " << std::put_time(local, "%Y/%m/%d %H:%M:%S") << ". Duration: " << trackList->durationTrack[value] << " sec" << std::endl;
    }
};

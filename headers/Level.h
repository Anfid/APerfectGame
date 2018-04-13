#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    Level();
    ~Level();

    /* void load(...)
     * Parses .xml file and loads level data
     */
    void load(int x, int y);

};

#endif // LEVEL_H

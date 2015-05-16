#include "Stage.h"
#include "Define.h"
#include "../cocos2d/external/unzip/unzip.h"

USING_NS_CC;

Stage::Stage(const char *stageZip, cocos2d::Layer *layer)
{
    // TODO: extract map & bgm info from stage zip
    extractZip(stageZip);

    map = new TileMap(layer);

    rhythm = new RhythmEngine();
    rhythm->setBGM("music/sample.mp3");
    rhythm->setEffect("music/knock.mp3");
}

void Stage::extractZip(const char *stageZip)
{
    unzFile zipfile = unzOpen(stageZip);

    if(zipfile == NULL) {
        return;
    }
    
    unz_global_info global_info;
    if(unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK) {
        unzClose(zipfile);
        return;
    }

    for(int i = 0 ; i < global_info.number_entry ; i++) {
        unz_file_info file_info;
        char filename[100];
        if(unzGetCurrentFileInfo(zipfile, &file_info, filename, 100, 
                    NULL, 0, NULL, 0) != UNZ_OK) {
            unzClose(zipfile);
            return;
        }

        char read_buffer[512];
        const size_t filename_length = strlen(filename);

        if(filename[filename_length - 1] == '/') {
            // directory...
        }
        else {
            // file
            if(unzOpenCurrentFile(zipfile) != UNZ_OK) {
                unzClose(zipfile);
                return;
            }

            FILE *fout = fopen("", "wb");

            int error = UNZ_OK;
            do {
                error = unzReadCurrentFile(zipfile, read_buffer, 512);
                if(error < 0) {
                    unzCloseCurrentFile(zipfile);
                    unzClose(zipfile);
                    return;
                }

                if(error > 0) {
                    fwrite(read_buffer, error, 1, fout);
                }
            } while(error > 0);

            fclose(fout);
        }
        unzCloseCurrentFile(zipfile);

        if((i + 1) < global_info.number_entry) {
            if(unzGoToNextFile(zipfile) != UNZ_OK) {
                unzClose(zipfile);
                return;
            }
        }
    }
    unzClose(zipfile);
}

RhythmEngine *Stage::getRhythmEngine()
{
    return rhythm;
}

int Stage::getBPM() 
{
    return bpm;
}

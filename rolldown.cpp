#include <iostream>
#include <sstream>
#include <alsa/asoundlib.h> // # apt-get install libasound2-dev
using namespace std;

// constant data
const char* card = "default";
const char* selem_name = "Master";

// global data
long vmin, vmax, volume, step;

// handles
snd_mixer_t *handle;
snd_mixer_selem_id_t *sid;
snd_mixer_elem_t* elem;

// functions
void sound_init();
void step_down();
string get_current_volume_string();

// main
int main() {

    // set up sound api
    sound_init();

    // print starting volume
    cout << get_current_volume_string() << endl;

    do {
        // wait five minutes
        sleep(5 * 60 ); 
        // reduce volume
        step_down();
    }
    // stop at 10% (step is 2%)
    while(volume > step*5);
     
    // close down
    snd_mixer_close(handle);
    return 0;
}

void sound_init() {

    // set up sound api
    snd_mixer_open(&handle,0);
    snd_mixer_attach(handle,card);
    snd_mixer_selem_register(handle,NULL,NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid,0);
    snd_mixer_selem_id_set_name(sid,selem_name);
    elem=snd_mixer_find_selem(handle,sid);

    snd_mixer_selem_get_playback_volume_range(elem,&vmin,&vmax);

    // calculate volume step (2%)
    step = vmax * .02;

}

void step_down() {

    // reduce by one step
    volume -= step;

    // set new volume
    snd_mixer_selem_set_playback_volume_all(elem, volume );

    // print new volume
    cout << get_current_volume_string() << endl;

}

string get_current_volume_string() {

    // get current volume
    snd_mixer_selem_get_playback_volume(elem,SND_MIXER_SCHN_MONO,&volume);

    /// TODO: 
    //   * Get timestamp

    // assemble volume string
    ostringstream volume_string;
    volume_string << "Current volume: " << volume;

    // return it
    return volume_string.str();
}


/* sound_sdl2_test.c
 *
 * This file is part of fizmo.
 *
 * Copyright (c) 2009-2016 Christoph Ender.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#define _POSIX_C_SOURCE 1
#define _XOPEN_SOURCE 1



#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <stdio.h>

#include <SDL.h>
#include <SDL_main.h>
#include <SDL_audio.h>
#include <SDL_thread.h>

#include "sound_interface/sound_interface.h"
#include "tools/tracelog.h"
#include "tools/unused.h"
#include "tools/filesys.h"
#include "interpreter/zpu.h"
#include "interpreter/config.h"
#include "interpreter/fizmo.h"
#include "interpreter/streams.h"
#include "interpreter/blorb.h"
#include SOUND_INTERFACE_INCLUDE_FILE


// volume: 1-8, 8 being loudest
// repeats: 1-254, 255 means forever
// routine: set "start_interrupt_routine" to (routine) when sound
//    finishes (00 for don't call anything).

// struct z_sound_interface
// {
//   void (*init_sound)();
//   void (*close_sound)();
//   void (*prepare_sound)(int sound_nr, int volume, int repeats);
//   void (*play_sound)(int sound_nr, int volume, int repeats, uint16_t routine);
//   void (*stop_sound)(int sound_nr);
//   void (*finish_sound)(int sound_nr);
//   void (*keyboard_input_has_occurred)();
//   uint16_t (*get_next_sound_end_routine)();
//   char* (*get_interface_name)();
//   char* (*get_interface_version)();
//   int (*parse_config_parameter)(char *key, char *value);
//   char* (*get_config_value)(char *key);
//   char **(*get_config_option_names)();
// };


int main(int argc, char **argv) {
  int i;

  turn_on_trace();
  struct z_sound_interface *sound_interface = &SOUND_INTERFACE_STRUCT_NAME;
  sound_interface->init_sound("/Users/chrender/swp06/libsndifsdl2-test/SHERLOCK.z5");
  for (i=1; i<=17; i++) {
    sound_interface->play_sound(i, 8, 1, 0);
  }
  sleep(100);
  sound_interface->close_sound();

  return 0;
}


//
// libtgvoip is free and unencumbered public domain software.
// For more information, see http://unlicense.org or the UNLICENSE file
// you should have received with this source code distribution.
//

#ifndef LIBTGVOIP_AUDIOINPUTWAVE_H
#define LIBTGVOIP_AUDIOINPUTWAVE_H

#include <windows.h>
#include "../../audio/AudioInput.h"

namespace tgvoip{
namespace audio{

class AudioInputWave : public CAudioInput{

public:
	AudioInputWave();
	virtual ~AudioInputWave();
	virtual void Configure(uint32_t sampleRate, uint32_t bitsPerSample, uint32_t channels);
	virtual void Start();
	virtual void Stop();

private:
	static void CALLBACK WaveInProc(HWAVEIN hwi, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
	void OnData(WAVEHDR* hdr);
	HWAVEIN hWaveIn;
	WAVEFORMATEX format;
	WAVEHDR buffers[4];
	bool isRecording;
};

}
}

#endif //LIBTGVOIP_AUDIOINPUTWAVE_H

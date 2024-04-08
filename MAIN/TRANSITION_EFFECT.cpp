#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "TRANSITION_EFFECT.h"

TRANSITION_EFFECT::TRANSITION_EFFECT()
{
	Alpha = 255;
	Red = 0;
	Green = 0;
	Blue = 0;
	//�t�F�[�h�A�E�g���J�n����t�F�[�h�C�����I���܂ł̎��ԁi�b�j
	float time = 1.0f;
	Speed = 255 / (time * 0.5f);
	State = IN_START;
}

TRANSITION_EFFECT::~TRANSITION_EFFECT()
{
}

void TRANSITION_EFFECT::setTime(float time)
{
	Speed = 255 / (time * 0.5f);
}

void TRANSITION_EFFECT::inStart()
{
	if (State == OUT_END) {
		State = IN_START;
	}
}

bool TRANSITION_EFFECT::inEndFlag()
{
	return State == IN_START;
}

void TRANSITION_EFFECT::outStart()
{
	if (State == IN_END) {
		State = OUT_START;
	}
}

bool TRANSITION_EFFECT::outEndFlag()
{
	return State == OUT_END;
}

void TRANSITION_EFFECT::proc()
{
	//�t�F�[�h�C�����̓A�E�g���I�����Ă���Ƃ��͉������Ȃ�
	if (State == IN_END ||
		State == OUT_END) {
		return;
	}
	//�t�F�[�h�C���E�A�E�g���ʏ���
	noStroke();
	rectMode(CORNER);
	colorMode(RGB);
	fill(Red, Green, Blue, Alpha);
	//�t�F�[�h�C��
	if (State == IN_START) {
		rect(0, 0, width, height);
		Alpha -= Speed * delta;
		if (Alpha <= 0) {
			Alpha = 0;
			State = IN_END;
		}
		return;
	}
	//�t�F�[�h�A�E�g
	if (State == OUT_START) {
		rect(0, 0, width, height);
		Alpha += Speed * delta;
		if (Alpha >= 255) {
			Alpha = 255;
			State = OUT_END;
		}
	}
}
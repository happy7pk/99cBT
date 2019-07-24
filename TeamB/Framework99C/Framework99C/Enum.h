#pragma once

#ifndef __ENUM__H__

//가장 처음 enum은 수정 x


enum OBJECT_TYPE { PLAYER, MONSTER, OBJECT_END};

//유리
enum PLAYER_LEVEL {PL01}; //레벨에 따른 공격모양 변경
enum PLAYER_STATE {PS01}; //플레이어 상태 타격당할때상태, 일반     +   회피, 무적 등..

//정우
enum MON_STATE{MS01};		 //타격당할때, 평소상태, 폭발상태       + 등등
enum MON_MOV_PATTERN{MMP01 , MMP02, MMP03, MMP04}; //몬스터의 패턴
enum MON_ATT_PATTERN{MAP01}; //공격 패턴
enum MON_TYPE		{MT01}; //몬스터 타입(외형)
enum MON_MOVE_TYPE{NOMOVE,MMT01,MMT02,MMT03,MMT04};
//공용
enum BULLET_TYPE { BT01 };     //총알 종류,  기본,Level1,2,3 , 필살기, 몬스터총알    + 등등
enum BULLET_PATTERN {P01,P02,P03,P04,P05};
//현우
enum MAIN_STATE  {MAIN,PLAY,PAUSE,CLEAR,GAMEOVER};	  //메인,게임진행중,게임오버, 클리어 , + 등등 

enum MONSTER_MOVING_DIRECT { REVERSE = -1, NORMAL = 1 };

#define __ENUM__H__
#endif

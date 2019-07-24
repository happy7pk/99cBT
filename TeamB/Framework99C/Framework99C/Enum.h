#pragma once

#ifndef __ENUM__H__

//���� ó�� enum�� ���� x


enum OBJECT_TYPE { PLAYER, MONSTER, OBJECT_END};

//����
enum PLAYER_LEVEL {PL01}; //������ ���� ���ݸ�� ����
enum PLAYER_STATE {PS01}; //�÷��̾� ���� Ÿ�ݴ��Ҷ�����, �Ϲ�     +   ȸ��, ���� ��..

//����
enum MON_STATE{MS01};		 //Ÿ�ݴ��Ҷ�, ��һ���, ���߻���       + ���
enum MON_MOV_PATTERN{MMP01 , MMP02, MMP03, MMP04}; //������ ����
enum MON_ATT_PATTERN{MAP01}; //���� ����
enum MON_TYPE		{MT01}; //���� Ÿ��(����)
enum MON_MOVE_TYPE{NOMOVE,MMT01,MMT02,MMT03,MMT04};
//����
enum BULLET_TYPE { BT01 };     //�Ѿ� ����,  �⺻,Level1,2,3 , �ʻ��, �����Ѿ�    + ���
enum BULLET_PATTERN {P01,P02,P03,P04,P05};
//����
enum MAIN_STATE  {MAIN,PLAY,PAUSE,CLEAR,GAMEOVER};	  //����,����������,���ӿ���, Ŭ���� , + ��� 

enum MONSTER_MOVING_DIRECT { REVERSE = -1, NORMAL = 1 };

#define __ENUM__H__
#endif

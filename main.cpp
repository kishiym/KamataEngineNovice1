#include <Novice.h>

const char kWindowTitle[] = "";

void Move(int& player_posX, int& player_posY, int& speed, char* keys, char* preKeys,int(*map)[25])
{
	/*int map[25][25] =
	{
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};*/

	int player_radius = 16;
	int playerLeftTopX = (player_posX - player_radius) / 32;
	int playerLeftTopY = (player_posY - player_radius) / 32;

	int playerRightTopX = (player_posX + player_radius - 1) / 32;
	int playerRightTopY = (player_posY - player_radius) / 32;
	int playerLeftBottomX = (player_posX - player_radius) / 32;
	int playerLeftBottomY = (player_posY + player_radius - 1) / 32;
	int playerRightBottomX = (player_posX + player_radius - 1) / 32;
	int playerRightBottomY = (player_posY + player_radius - 1) / 32;

	if (keys[DIK_W])
	{
		playerLeftTopY  = (player_posY - player_radius - speed) / 32;
		playerRightTopY = (player_posY - player_radius - speed) / 32;

		if (map[playerLeftTopY][playerLeftTopX] == 0 && map[playerRightTopY][playerRightTopX] == 0)
		{
			player_posY -= speed;
		}
		playerLeftTopY = (player_posY - player_radius) / 32;
		playerRightTopY = (player_posY - player_radius) / 32;

		if (keys[DIK_D])
		{
			playerRightTopX    = (player_posX + player_radius - 1 + speed) / 32;
			playerRightBottomX = (player_posX + player_radius - 1 + speed) / 32;
			if (map[playerRightTopY][playerRightTopX] == 0 && map[playerRightBottomY][playerRightBottomX] == 0)
			{
				player_posX += speed;
				playerRightTopY = (player_posY - player_radius - speed) / 32;
				playerLeftTopY = (player_posY - player_radius - speed) / 32;
				if (map[playerRightTopY][playerRightTopX] == 1||map[playerLeftTopY][playerLeftTopX]==1)
				{
					player_posX -= speed / 2;
				}
			}
			else
			{
				player_posX = playerRightTopX * 32 - 16;

				playerRightTopX = (player_posX + player_radius - 1) / 32;
				playerRightBottomX = (player_posX + player_radius - 1) / 32;
				playerLeftBottomX = (player_posX - player_radius) / 32;

				playerLeftTopX = (player_posX - player_radius) / 32;


				playerRightTopY = (player_posY - player_radius - speed) / 32;
				playerLeftTopY = (player_posY - player_radius - speed) / 32;
				if (map[playerRightTopY][playerRightTopX] == 0 && map[playerLeftTopY][playerLeftTopX] == 0)
				{
					player_posY += speed / 2;
				}
				else
				{
					player_posY = playerRightBottomY * 32 - 16;
				}
			}

		}
		else if (keys[DIK_A])
		{
			playerLeftBottomX = (player_posX - player_radius - speed ) / 32;
			playerLeftTopX    = (player_posX - player_radius - speed ) / 32;

			if (map[playerLeftBottomY][playerLeftBottomX] == 0 && map[playerLeftTopY][playerLeftTopX] == 0)
			{
				player_posX -= speed ;
			}
			else
			{
				playerLeftBottomX = (player_posX - player_radius) / 32;
				playerLeftTopX    = (player_posX - player_radius) / 32;
				if (map[playerLeftTopY - 1][playerLeftTopX] == 0)
				{

				}
			}

		}

	}

	else if (keys[DIK_S])
	{
		playerLeftBottomY = (player_posY + player_radius - 1 + speed) / 32;
		playerRightBottomY = (player_posY + player_radius - 1 + speed) / 32;

		if (map[playerLeftBottomY][playerLeftBottomX] == 0 && map[playerRightBottomY][playerRightBottomX] == 0)
		{
			player_posY += speed;
		}
		else
		{
			playerLeftBottomY = (player_posY + player_radius - 1) / 32;
			playerRightBottomY = (player_posY + player_radius - 1) / 32;

		}
		if (keys[DIK_A])
		{
			playerLeftBottomX = (player_posX - player_radius - speed) / 32;
			playerLeftTopX = (player_posX - player_radius - speed) / 32;

			if (map[playerLeftBottomY][playerLeftBottomX] == 0 && map[playerLeftTopY][playerLeftTopX] == 0)
			{
				player_posX -= speed;
			}
			else
			{
				playerLeftBottomX = (player_posX - player_radius) / 32;
				playerLeftTopX = (player_posX - player_radius) / 32;

			}

		}
		if (keys[DIK_D])
		{
			playerRightTopX = (player_posX + player_radius - 1 + speed) / 32;
			playerRightBottomX = (player_posX + player_radius - 1 + speed) / 32;

			if (map[playerRightTopY][playerRightTopX] == 0 && map[playerRightBottomY][playerRightBottomX] == 0)
			{
				player_posX += speed;
			}
			else
			{
				playerRightTopX = (player_posX + player_radius - 1) / 32;
				playerRightBottomX = (player_posX + player_radius - 1) / 32;
			}
		}



	}
	else if (keys[DIK_D])
	{
		playerRightTopX = (player_posX + player_radius - 1 + speed) / 32;
		playerRightBottomX = (player_posX + player_radius - 1 + speed) / 32;
		if (map[playerRightTopY][playerRightTopX] == 0 && map[playerRightBottomY][playerRightBottomX] == 0)
		{
			player_posX += speed;
		}
		else
		{
			playerRightTopX = (player_posX + player_radius - 1) / 32;
			playerRightBottomX = (player_posX + player_radius - 1) / 32;
		}
	}
	else if (keys[DIK_A])
	{
		playerLeftBottomX = (player_posX - player_radius - speed) / 32;
		playerLeftTopX = (player_posX - player_radius - speed) / 32;

		if (map[playerLeftBottomY][playerLeftBottomX] == 0 && map[playerLeftTopY][playerLeftTopX] == 0)
		{
			player_posX -= speed;
		}
		else
		{
			playerLeftBottomX = (player_posX - player_radius) / 32;
			playerLeftTopX = (player_posX - player_radius) / 32;
		}
	}
	Novice::ScreenPrintf(0, 0, "player_RightTopMap[%d][%d]", playerRightTopY, playerRightTopX);
	Novice::ScreenPrintf(0, 20, "player_LeftTopMap[%d][%d]", playerLeftTopY, playerLeftTopX);
	Novice::ScreenPrintf(0, 40, "player_RightBottomMap[%d][%d]", playerRightBottomY, playerRightBottomX);
	Novice::ScreenPrintf(0, 60, "player_LeftBottomMap[%d][%d]", playerLeftBottomY, playerLeftBottomX);

}
// Windows??????????????????????????????????????????(main??????)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ???????????????????????????
	const int kWindowWidth = 800;
	const int kWindowHeight = 800;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// ????????????????????????????????????
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//?????????????????????
	const int block_size = 32;
	int map[25][25] =
	{
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int player_posX = 48;
	int player_posY = 80;
	int player_radius = 16;
	int speed = 2;

	//??????
	int playerLeftTopX;
	int playerLeftTopY;
	//??????
	int playerRightTopX;
	int playerRightTopY;
	//??????
	int playerLeftBottomX;
	int playerLeftBottomY;
	//??????
	int playerRightBottomX;
	int playerRightBottomY;

	int speedX = 0;
	int speedY = 0;
	int speedTmp = 2;

	//???????????????
	int Jamp = 32;
	//??????
	int G = 1;
	int randX = 0;
	int flag = 0;
	int flame=60;
	/*int x = 16;
	int y = 16;*/
	//int speed = 2;
	// ???????????????????????????????????????????????????????????
	while (Novice::ProcessMessage() == 0) {
		// ?????????????????????
		Novice::BeginFrame();

		// ???????????????????????????
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ???????????????????????????
		///
		if (keys[DIK_SPACE])
		{
			flag = 1;
			flame = 60;
		}
		if (flag == 1)
		{
			randX = rand() % 21 - 10;
			flame--;
			if (flame <= 0)
			{
				flag = 0;
				randX = 0;
			}

		}
		
		Move(player_posX, player_posY, speed, keys, preKeys,map);
		//Move(x,y,speed);
		//playerLeftTopX = (player_posX - player_radius) / 32;
		//playerLeftTopY = (player_posY - player_radius) / 32;

		//playerRightTopX = (player_posX + player_radius - 1) / 32;
		//playerRightTopY = (player_posY - player_radius) / 32;

		//playerLeftBottomX = (player_posX - player_radius) / 32;
		//playerLeftBottomY = (player_posY + player_radius - 1) / 32;

		//playerRightBottomX = (player_posX + player_radius - 1) / 32;
		//playerRightBottomY = (player_posY + player_radius - 1) / 32;

		//speedX = 0;
		//speedY += G;

		//if (keys[DIK_D])
		//{
		//	playerRightTopX = (player_posX + player_radius - 1 + speedTmp) / 32;
		//	playerRightBottomX = (player_posX + player_radius - 1 + speedTmp) / 32;
		//	if (map[playerRightTopY][playerRightTopX] == 0 && map[playerRightBottomY][playerRightBottomX] == 0)
		//	{
		//		speedX = speedTmp;
		//	}
		//	playerRightTopX = (player_posX + player_radius - 1) / 32;
		//	playerRightBottomX = (player_posX + player_radius - 1) / 32;

		//}
		//if (keys[DIK_A])
		//{
		//	playerLeftTopX = (player_posX - player_radius - speedTmp) / 32;
		//	playerLeftBottomX = (player_posX - player_radius - speedTmp) / 32;
		//	if (map[playerLeftTopY][playerLeftTopX] == 0 && map[playerRightBottomY][playerRightBottomX] == 0)
		//	{
		//		speedX = -speedTmp;
		//	}
		//	playerLeftTopX = (player_posX - player_radius) / 32;
		//	playerLeftBottomX = (player_posX - player_radius) / 32;

		//}
		//?????????????????????????????????????????????2??????y?????????????????????????????????
		//playerRightBottomY = (player_posY + player_radius - 1 + speedY) / 32;
		//playerLeftBottomY = (player_posY + player_radius - 1 + speedY) / 32;

		////????????????????????????2???????????????????????????????????????????????????????????????0?????????y?????????y???????????????????????????????????????
		//if (map[playerLeftBottomY][playerLeftBottomX] == 1 || map[playerRightBottomY][playerRightBottomX] == 1)
		//{
		//	speedY = 0;
		//	player_posY = playerRightBottomY * 32 - player_radius;
		//	playerRightBottomY = (player_posY + player_radius - 1) / 32;
		//	playerLeftBottomY = (player_posY + player_radius - 1) / 32;

		//}
		////space???????????????????????????????????????????????????????????????????????????
		//if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		//{
		//	playerLeftTopY = (player_posY - player_radius - Jamp) / 32;
		//	playerRightTopY = (player_posY - player_radius - Jamp) / 32;
		//	if (map[playerLeftTopY][playerLeftTopX] == 0 && map[playerRightTopY][playerRightTopX] == 0)
		//	{
		//		player_posY -= Jamp;
		//	}
		//}
		//player_posX += speedX;
		//player_posY += speedY;
		/////
		///// ???????????????????????????
		/////
		////Move(player_posX, player_posY,speed, keys,preKeys);
		///*playerLeftTopX = (player_posX - player_radius) / 32;
		//playerLeftTopY = (player_posY - player_radius) / 32;

		//playerRightTopX = (player_posX + player_radius - 1) / 32;
		//playerRightTopY = (player_posY - player_radius) / 32;

		//playerLeftBottomX = (player_posX - player_radius) / 32;
		//playerLeftBottomY = (player_posY + player_radius - 1) / 32;

		//playerRightBottomX = (player_posX + player_radius - 1) / 32;
		//playerRightBottomY = (player_posY + player_radius - 1) / 32;*/

		///
		/// ???????????????????????????
		///
		Novice::DrawBox(player_posX - player_radius + randX, player_posY - player_radius + randX, player_radius * 2, player_radius * 2, 0.0f, WHITE, kFillModeSolid);
		for (int y = 0; y < 25; y++)
		{
			for (int x = 0; x < 25; x++)
			{
				if (map[y][x] == 1)
				{
					Novice::DrawBox(x * 32+randX, y * 32+randX, 32, 32, 0.0f, BLACK, kFillModeSolid);
				}
			}
		}
	


		///
		/// ???????????????????????????
		///

		// ?????????????????????
		Novice::EndFrame();

		// ESC?????????????????????????????????????????????
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ????????????????????????
	Novice::Finalize();
	return 0;
}

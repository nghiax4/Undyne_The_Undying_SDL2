emcc -g \
src/main.cpp src/MenuButton.cpp src/Player.cpp src/Utils.cpp src/GameObject.cpp src/SelectedMenuButtonContainer.cpp src/BattleBox.cpp src/Undyne.cpp src/GameManager.cpp src/Shield.cpp src/Player_EnemyTurn_Green.cpp src/Attack_0_Manager.cpp src/Arrow_For_Green_Attack.cpp src/Player_EnemyTurn.cpp src/Attack_Manager_Base_Class.cpp src/Attack_1_Manager.cpp src/Attack_2_Manager.cpp src/Attack_3_Manager.cpp src/White_Arrow_Small_Box_Attack.cpp src/HealthPointText.cpp src/Attack_4_Manager.cpp src/White_Arrow_Medium_Box_Attack.cpp src/Attack_5_Manager.cpp \
-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 -s USE_SDL_TTF=2 \
--use-preload-plugins \
--preload-file sprites \
--preload-file audio \
--preload-file font.ttf \
-s INITIAL_MEMORY=134217728 \
-o index.html
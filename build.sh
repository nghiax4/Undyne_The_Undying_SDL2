emcc -g \
src/main.cpp src/MenuButton.cpp src/Player.cpp src/Utils.cpp src/GameObject.cpp src/SelectedMenuButtonContainer.cpp src/BattleBox.cpp src/Undyne.cpp src/GameManager.cpp src/Shield.cpp src/Player_EnemyTurn_Green.cpp src/Attack_0_Manager.cpp src/Arrow_For_Green_Attack.cpp src/Attack_Manager_Base_Class.cpp \
-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 \
--use-preload-plugins \
--preload-file sprites \
--preload-file music.ogg \
--preload-file menu_select_sound.ogg \
--preload-file shield_reflect.ogg \
-s INITIAL_MEMORY=134217728 \
-o index.html
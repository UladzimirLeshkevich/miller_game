//все треугольники тут
#pragma once

//===== герой =====
triangle hero, hero1, hero2, hero3, hero4, hero5, hero6, hero7;

//главный герой как на текстуре смотрит вправо
hero.v[0] = { -0.8794233f, -0.5f, 0.0f, 1.0f };
hero.v[1] = { -0.8794233f, 0.0f, 0.0f, 0.0f };
hero.v[2] = { -0.5f, -0.5f, 1.0f, 1.0f };

hero1.v[0] = { -0.5f, 0.0f, 1.0f, 0.0f };
hero1.v[1] = { -0.8794233f, 0.0f, 0.0f, 0.0f };
hero1.v[2] = { -0.5f, -0.5f, 1.0f, 1.0f };

//главный герой смотрит влево
hero2.v[0] = { -0.8794233f, -0.5f, 1.0f, 1.0f };
hero2.v[1] = { -0.8794233f, 0.0f, 1.0f, 0.0f };
hero2.v[2] = { -0.5f, -0.5f, 0.0f, 1.0f };

hero3.v[0] = { -0.5f, 0.0f, 0.0f, 0.0f };
hero3.v[1] = { -0.8794233f, 0.0f, 1.0f, 0.0f };
hero3.v[2] = { -0.5f, -0.5f, 0.0f, 1.0f };

//главный герой умирает в окне game over
hero4.v[0] = { -0.7193467337f, -0.5f, 0.0f, 1.0f };
hero4.v[1] = { -0.7193467337f, 0.0f, 0.0f, 0.0f };
hero4.v[2] = { -0.1f, -0.5f, 1.0f, 1.0f };

hero5.v[0] = { -0.1f, 0.0f, 1.0f, 0.0f };
hero5.v[1] = { -0.7193467337f, 0.0f, 0.0f, 0.0f };
hero5.v[2] = { -0.1f, -0.5f, 1.0f, 1.0f };

//главный герой в окне pause
hero6.v[0] = { -0.8794233f, -0.5f, 0.0f, 1.0f };
hero6.v[1] = { -0.8794233f, 0.0f, 0.0f, 0.0f };
hero6.v[2] = { -0.5f, -0.5f, 1.0f, 1.0f };

hero7.v[0] = { -0.5f, 0.0f, 1.0f, 0.0f };
hero7.v[1] = { -0.8794233f, 0.0f, 0.0f, 0.0f };
hero7.v[2] = { -0.5f, -0.5f, 1.0f, 1.0f };

//длинный огонь на весь экран
triangle l_fire, l_fire2, l_fire3, l_fire4;

l_fire.v[0] = { -1.0f, -1.0f, 0.0f, 1.0f };
l_fire.v[1] = { -1.0f, -0.8f, 0.0f, 0.0f };
l_fire.v[2] = { 0.1f, -1.0f, 1.0f, 1.0f };

l_fire2.v[0] = { 0.1f, -0.8f, 1.0f, 0.0f };
l_fire2.v[1] = { -1.0f, -0.8f, 0.0f, 0.0f };
l_fire2.v[2] = { 0.1f, -1.0f, 1.0f, 1.0f };

l_fire3.v[0] = { -0.1f, -1.0f, 0.0f, 1.0f };
l_fire3.v[1] = { -0.1f, -0.8f, 0.0f, 0.0f };
l_fire3.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

l_fire4.v[0] = { 1.0f, -0.8f, 1.0f, 0.0f };
l_fire4.v[1] = { -0.1f, -0.8f, 0.0f, 0.0f };
l_fire4.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

//земля 3 куска
triangle ground, ground1;
triangle ground2, ground3;
//основная земля на весь экран ГОРИТ !!!
triangle ground4, ground5, ground6, ground7, ground8, ground9;

//земля
ground.v[0] = { -0.9f, -0.6f, 0.0f, 1.0f };
ground.v[1] = { -0.9f, -0.3f, 0.0f, 0.0f };
ground.v[2] = { -0.3f, -0.6f, 1.0f, 1.0f };

ground1.v[0] = { -0.3f, -0.3f, 1.0f, 0.0f };
ground1.v[1] = { -0.9f, -0.3f, 0.0f, 0.0f };
ground1.v[2] = { -0.3f, -0.6f, 1.0f, 1.0f };

ground2.v[0] = { 0.3f, -1.0f, 0.0f, 1.0f };
ground2.v[1] = { 0.3f, -0.8f, 0.0f, 0.0f };
ground2.v[2] = { 0.9f, -1.0f, 1.0f, 1.0f };

ground3.v[0] = { 0.9f, -0.8f, 1.0f, 0.0f };
ground3.v[1] = { 0.3f, -0.8f, 0.0f, 0.0f };
ground3.v[2] = { 0.9f, -1.0f, 1.0f, 1.0f };

ground4.v[0] = { -1.0f, -1.0f, 0.0f, 1.0f };
ground4.v[1] = { -1.0f, -0.7f, 0.0f, 0.0f };
ground4.v[2] = { -0.25f, -1.0f, 1.0f, 1.0f };

ground5.v[0] = { -0.25f, -0.7f, 1.0f, 0.0f };
ground5.v[1] = { -1.0f, -0.7f, 0.0f, 0.0f };
ground5.v[2] = { -0.25f, -1.0f, 1.0f, 1.0f };

ground6.v[0] = { -0.35f, -1.0f, 0.0f, 1.0f };
ground6.v[1] = { -0.35f, -0.7f, 0.0f, 0.0f };
ground6.v[2] = { 0.35f, -1.0f, 1.0f, 1.0f };

ground7.v[0] = { 0.35f, -0.7f, 1.0f, 0.0f };
ground7.v[1] = { -0.35f, -0.7f, 0.0f, 0.0f };
ground7.v[2] = { 0.35f, -1.0f, 1.0f, 1.0f };

ground8.v[0] = { 0.25f, -1.0f, 0.0f, 1.0f };
ground8.v[1] = { 0.25f, -0.7f, 0.0f, 0.0f };
ground8.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

ground9.v[0] = { 1.0f, -0.7f, 1.0f, 0.0f };
ground9.v[1] = { 0.25f, -0.7f, 0.0f, 0.0f };
ground9.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

// ALARM 1 !! (горит мельница 1)
triangle bell, bell1;
bell.v[0] = { -0.85f, 0.3f, 0.0f, 1.0f };
bell.v[1] = { -0.85f, 0.7f, 0.0f, 0.0f };
bell.v[2] = { -0.45f, 0.3f, 1.0f, 1.0f };

bell1.v[0] = { -0.45f, 0.7f, 1.0f, 0.0f };
bell1.v[1] = { -0.85f, 0.7f, 0.0f, 0.0f };
bell1.v[2] = { -0.45f, 0.3f, 1.0f, 1.0f };

// ALARM 2 !! (горит мельница 2 правая)
triangle bell2, bell3;
bell2.v[0] = { 0.45f, 0.3f, 0.0f, 1.0f };
bell2.v[1] = { 0.45f, 0.7f, 0.0f, 0.0f };
bell2.v[2] = { 0.85f, 0.3f, 1.0f, 1.0f };

bell3.v[0] = { 0.85f, 0.7f, 1.0f, 0.0f };
bell3.v[1] = { 0.45f, 0.7f, 0.0f, 0.0f };
bell3.v[2] = { 0.85f, 0.3f, 1.0f, 1.0f };

// ALARM 3 !! (горит мельница 3 центр)
triangle bell4, bell5;
bell4.v[0] = { -0.2f, 0.3f, 0.0f, 1.0f };
bell4.v[1] = { -0.2f, 0.7f, 0.0f, 0.0f };
bell4.v[2] = { 0.2f, 0.3f, 1.0f, 1.0f };

bell5.v[0] = { 0.2f, 0.7f, 1.0f, 0.0f };
bell5.v[1] = { -0.2f, 0.7f, 0.0f, 0.0f };
bell5.v[2] = { 0.2f, 0.3f, 1.0f, 1.0f };

//огонь слева (горит мельница 1)
triangle fire, fire1;
fire.v[0] = { -0.85f, -1.3f, 0.0f, 1.0f };
fire.v[1] = { -0.85f, -0.9f, 0.0f, 0.0f };
fire.v[2] = { -0.45f, -1.3f, 1.0f, 1.0f };

fire1.v[0] = { -0.45f, -0.9f, 1.0f, 0.0f };
fire1.v[1] = { -0.85f, -0.9f, 0.0f, 0.0f };
fire1.v[2] = { -0.45f, -1.3f, 1.0f, 1.0f };

//огонь посередине (горит мельница 3)
triangle fire2, fire3;
fire2.v[0] = { -0.2f, -1.3f, 0.0f, 1.0f };
fire2.v[1] = { -0.2f, -0.9f, 0.0f, 0.0f };
fire2.v[2] = { 0.2f, -1.3f, 1.0f, 1.0f };

fire3.v[0] = { 0.2f, -0.9f, 1.0f, 0.0f };
fire3.v[1] = { -0.2f, -0.9f, 0.0f, 0.0f };
fire3.v[2] = { 0.2f, -1.3f, 1.0f, 1.0f };

//огонь справа (горит мельница 2)
triangle fire4, fire5;
fire4.v[0] = { 0.45f, -1.3f, 0.0f, 1.0f };
fire4.v[1] = { 0.45f, -0.9f, 0.0f, 0.0f };
fire4.v[2] = { 0.85f, -1.3f, 1.0f, 1.0f };

fire5.v[0] = { 0.85f, -0.9f, 1.0f, 0.0f };
fire5.v[1] = { 0.45f, -0.9f, 0.0f, 0.0f };
fire5.v[2] = { 0.85f, -1.3f, 1.0f, 1.0f };

//облако
triangle cloud, cloud1;

cloud.v[0] = { -0.9f, 0.7f, 0.0f, 1.0f };
cloud.v[1] = { -0.9f, 1.0f, 0.0f, 0.0f };
cloud.v[2] = { -0.4f, 0.7f, 1.0f, 1.0f };

cloud1.v[0] = { -0.4f, 1.0f, 1.0f, 0.0f };
cloud1.v[1] = { -0.9f, 1.0f, 0.0f, 0.0f };
cloud1.v[2] = { -0.4f, 0.7f, 1.0f, 1.0f };

//дождь
triangle drop, drop1, drop2, drop3, drop4, drop5, drop6, drop7, drop8, drop9,
    drop10, drop11, drop12, drop13, drop14, drop15, drop16, drop17, drop18,
    drop19, drop20, drop21, drop22, drop23, drop24, drop25, drop26, drop27,
    drop28, drop29, drop30, drop31, drop32, drop33, drop34, drop35, drop36,
    drop37, drop38, drop39, drop40, drop41, drop42, drop43, drop44, drop45,
    drop46, drop47, drop48, drop49;

//первый ряд дождя
//капля 1
drop.v[0] = { -0.9f, 0.6f, 0.0f, 1.0f };
drop.v[1] = { -0.9f, 0.8f, 0.0f, 0.0f };
drop.v[2] = { -0.85f, 0.6f, 1.0f, 1.0f };

drop1.v[0] = { -0.85f, 0.8f, 1.0f, 0.0f };
drop1.v[1] = { -0.9f, 0.8f, 0.0f, 0.0f };
drop1.v[2] = { -0.85f, 0.6f, 1.0f, 1.0f };

//капля 2
drop2.v[0] = { -0.8f, 0.5f, 0.0f, 1.0f };
drop2.v[1] = { -0.8f, 0.7f, 0.0f, 0.0f };
drop2.v[2] = { -0.75f, 0.5f, 1.0f, 1.0f };

drop3.v[0] = { -0.75f, 0.7f, 1.0f, 0.0f };
drop3.v[1] = { -0.8f, 0.7f, 0.0f, 0.0f };
drop3.v[2] = { -0.75f, 0.5f, 1.0f, 1.0f };

//капля 3
drop4.v[0] = { -0.7f, 0.4f, 0.0f, 1.0f };
drop4.v[1] = { -0.7f, 0.6f, 0.0f, 0.0f };
drop4.v[2] = { -0.65f, 0.4f, 1.0f, 1.0f };

drop5.v[0] = { -0.65f, 0.6f, 1.0f, 0.0f };
drop5.v[1] = { -0.7f, 0.6f, 0.0f, 0.0f };
drop5.v[2] = { -0.65f, 0.4f, 1.0f, 1.0f };

//капля 4
drop6.v[0] = { -0.6f, 0.3f, 0.0f, 1.0f };
drop6.v[1] = { -0.6f, 0.5f, 0.0f, 0.0f };
drop6.v[2] = { -0.55f, 0.3f, 1.0f, 1.0f };

drop7.v[0] = { -0.55f, 0.5f, 1.0f, 0.0f };
drop7.v[1] = { -0.6f, 0.5f, 0.0f, 0.0f };
drop7.v[2] = { -0.55f, 0.3f, 1.0f, 1.0f };

//капля 5
drop8.v[0] = { -0.5f, 0.2f, 0.0f, 1.0f };
drop8.v[1] = { -0.5f, 0.4f, 0.0f, 0.0f };
drop8.v[2] = { -0.45f, 0.2f, 1.0f, 1.0f };

drop9.v[0] = { -0.45f, 0.4f, 1.0f, 0.0f };
drop9.v[1] = { -0.5f, 0.4f, 0.0f, 0.0f };
drop9.v[2] = { -0.45f, 0.2f, 1.0f, 1.0f };

//второй ряд дождя
//капля 6
drop10.v[0] = { -0.9f, 0.2f, 0.0f, 1.0f };
drop10.v[1] = { -0.9f, 0.4f, 0.0f, 0.0f };
drop10.v[2] = { -0.85f, 0.2f, 1.0f, 1.0f };

drop11.v[0] = { -0.85f, 0.4f, 1.0f, 0.0f };
drop11.v[1] = { -0.9f, 0.4f, 0.0f, 0.0f };
drop11.v[2] = { -0.85f, 0.2f, 1.0f, 1.0f };

//капля 7
drop12.v[0] = { -0.8f, 0.1f, 0.0f, 1.0f };
drop12.v[1] = { -0.8f, 0.3f, 0.0f, 0.0f };
drop12.v[2] = { -0.75f, 0.1f, 1.0f, 1.0f };

drop13.v[0] = { -0.75f, 0.3f, 1.0f, 0.0f };
drop13.v[1] = { -0.8f, 0.3f, 0.0f, 0.0f };
drop13.v[2] = { -0.75f, 0.1f, 1.0f, 1.0f };

//капля 8
drop14.v[0] = { -0.7f, 0.0f, 0.0f, 1.0f };
drop14.v[1] = { -0.7f, 0.2f, 0.0f, 0.0f };
drop14.v[2] = { -0.65f, 0.0f, 1.0f, 1.0f };

drop15.v[0] = { -0.65f, 0.2f, 1.0f, 0.0f };
drop15.v[1] = { -0.7f, 0.2f, 0.0f, 0.0f };
drop15.v[2] = { -0.65f, 0.0f, 1.0f, 1.0f };

//капля 9
drop16.v[0] = { -0.6f, -0.1f, 0.0f, 1.0f };
drop16.v[1] = { -0.6f, 0.1f, 0.0f, 0.0f };
drop16.v[2] = { -0.55f, -0.1f, 1.0f, 1.0f };

drop17.v[0] = { -0.55f, 0.1f, 1.0f, 0.0f };
drop17.v[1] = { -0.6f, 0.1f, 0.0f, 0.0f };
drop17.v[2] = { -0.55f, -0.1f, 1.0f, 1.0f };

//капля 10
drop18.v[0] = { -0.5f, -0.2f, 0.0f, 1.0f };
drop18.v[1] = { -0.5f, -0.0f, 0.0f, 0.0f };
drop18.v[2] = { -0.45f, -0.2f, 1.0f, 1.0f };

drop19.v[0] = { -0.45f, -0.0f, 1.0f, 0.0f };
drop19.v[1] = { -0.5f, -0.0f, 0.0f, 0.0f };
drop19.v[2] = { -0.45f, -0.2f, 1.0f, 1.0f };

//третий ряд дождя
//капля 11
drop20.v[0] = { -0.9f, -0.2f, 0.0f, 1.0f };
drop20.v[1] = { -0.9f, -0.0f, 0.0f, 0.0f };
drop20.v[2] = { -0.85f, -0.2f, 1.0f, 1.0f };

drop21.v[0] = { -0.85f, -0.0f, 1.0f, 0.0f };
drop21.v[1] = { -0.9f, -0.0f, 0.0f, 0.0f };
drop21.v[2] = { -0.85f, -0.2f, 1.0f, 1.0f };

//капля 12
drop22.v[0] = { -0.8f, -0.3f, 0.0f, 1.0f };
drop22.v[1] = { -0.8f, -0.1f, 0.0f, 0.0f };
drop22.v[2] = { -0.75f, -0.3f, 1.0f, 1.0f };

drop23.v[0] = { -0.75f, -0.1f, 1.0f, 0.0f };
drop23.v[1] = { -0.8f, -0.1f, 0.0f, 0.0f };
drop23.v[2] = { -0.75f, -0.3f, 1.0f, 1.0f };

//капля 13
drop24.v[0] = { -0.7f, -0.4f, 0.0f, 1.0f };
drop24.v[1] = { -0.7f, -0.2f, 0.0f, 0.0f };
drop24.v[2] = { -0.65f, -0.4f, 1.0f, 1.0f };

drop25.v[0] = { -0.65f, -0.2f, 1.0f, 0.0f };
drop25.v[1] = { -0.7f, -0.2f, 0.0f, 0.0f };
drop25.v[2] = { -0.65f, -0.4f, 1.0f, 1.0f };

//капля 14
drop26.v[0] = { -0.6f, -0.5f, 0.0f, 1.0f };
drop26.v[1] = { -0.6f, -0.3f, 0.0f, 0.0f };
drop26.v[2] = { -0.55f, -0.5f, 1.0f, 1.0f };

drop27.v[0] = { -0.55f, -0.3f, 1.0f, 0.0f };
drop27.v[1] = { -0.6f, -0.3f, 0.0f, 0.0f };
drop27.v[2] = { -0.55f, -0.5f, 1.0f, 1.0f };

//капля 15
drop28.v[0] = { -0.5f, -0.6f, 0.0f, 1.0f };
drop28.v[1] = { -0.5f, -0.4f, 0.0f, 0.0f };
drop28.v[2] = { -0.45f, -0.6f, 1.0f, 1.0f };

drop29.v[0] = { -0.45f, -0.4f, 1.0f, 0.0f };
drop29.v[1] = { -0.5f, -0.4f, 0.0f, 0.0f };
drop29.v[2] = { -0.45f, -0.6f, 1.0f, 1.0f };

//четвертый ряд дождя
//капля 16
drop30.v[0] = { -0.9f, -0.6f, 0.0f, 1.0f };
drop30.v[1] = { -0.9f, -0.4f, 0.0f, 0.0f };
drop30.v[2] = { -0.85f, -0.6f, 1.0f, 1.0f };

drop31.v[0] = { -0.85f, -0.4f, 1.0f, 0.0f };
drop31.v[1] = { -0.9f, -0.4f, 0.0f, 0.0f };
drop31.v[2] = { -0.85f, -0.6f, 1.0f, 1.0f };

//капля 17
drop32.v[0] = { -0.8f, -0.7f, 0.0f, 1.0f };
drop32.v[1] = { -0.8f, -0.5f, 0.0f, 0.0f };
drop32.v[2] = { -0.75f, -0.7f, 1.0f, 1.0f };

drop33.v[0] = { -0.75f, -0.5f, 1.0f, 0.0f };
drop33.v[1] = { -0.8f, -0.5f, 0.0f, 0.0f };
drop33.v[2] = { -0.75f, -0.7f, 1.0f, 1.0f };

//капля 18 ////
drop34.v[0] = { -0.7f, -0.8f, 0.0f, 1.0f };
drop34.v[1] = { -0.7f, -0.6f, 0.0f, 0.0f };
drop34.v[2] = { -0.65f, -0.8f, 1.0f, 1.0f };

drop35.v[0] = { -0.65f, -0.6f, 1.0f, 0.0f };
drop35.v[1] = { -0.7f, -0.6f, 0.0f, 0.0f };
drop35.v[2] = { -0.65f, -0.8f, 1.0f, 1.0f };

//капля 19
drop36.v[0] = { -0.6f, -0.9f, 0.0f, 1.0f };
drop36.v[1] = { -0.6f, -0.7f, 0.0f, 0.0f };
drop36.v[2] = { -0.55f, -0.9f, 1.0f, 1.0f };

drop37.v[0] = { -0.55f, -0.7f, 1.0f, 0.0f };
drop37.v[1] = { -0.6f, -0.7f, 0.0f, 0.0f };
drop37.v[2] = { -0.55f, -0.9f, 1.0f, 1.0f };

//капля 20
drop38.v[0] = { -0.5f, -1.0f, 0.0f, 1.0f };
drop38.v[1] = { -0.5f, -0.8f, 0.0f, 0.0f };
drop38.v[2] = { -0.45f, -1.0f, 1.0f, 1.0f };

drop39.v[0] = { -0.45f, -0.8f, 1.0f, 0.0f };
drop39.v[1] = { -0.5f, -0.8f, 0.0f, 0.0f };
drop39.v[2] = { -0.45f, -1.0f, 1.0f, 1.0f };

//пятый ряд дождя
//капля 21
drop40.v[0] = { -0.9f, -0.9f, 0.0f, 1.0f };
drop40.v[1] = { -0.9f, -0.7f, 0.0f, 0.0f };
drop40.v[2] = { -0.85f, -0.9f, 1.0f, 1.0f };

drop41.v[0] = { -0.85f, -0.7f, 1.0f, 0.0f };
drop41.v[1] = { -0.9f, -0.7f, 0.0f, 0.0f };
drop41.v[2] = { -0.85f, -0.9f, 1.0f, 1.0f };

//капля 22
drop42.v[0] = { -0.8f, -1.0f, 0.0f, 1.0f };
drop42.v[1] = { -0.8f, -0.8f, 0.0f, 0.0f };
drop42.v[2] = { -0.75f, -1.0f, 1.0f, 1.0f };

drop43.v[0] = { -0.75f, -0.8f, 1.0f, 0.0f };
drop43.v[1] = { -0.8f, -0.8f, 0.0f, 0.0f };
drop43.v[2] = { -0.75f, -1.0f, 1.0f, 1.0f };

//капля 23
drop44.v[0] = { -0.7f, -1.1f, 0.0f, 1.0f };
drop44.v[1] = { -0.7f, -0.9f, 0.0f, 0.0f };
drop44.v[2] = { -0.65f, -1.1f, 1.0f, 1.0f };

drop45.v[0] = { -0.65f, -0.9f, 1.0f, 0.0f };
drop45.v[1] = { -0.7f, -0.9f, 0.0f, 0.0f };
drop45.v[2] = { -0.65f, -1.1f, 1.0f, 1.0f };

//капля 24
drop46.v[0] = { -0.6f, -1.2f, 0.0f, 1.0f };
drop46.v[1] = { -0.6f, -1.0f, 0.0f, 0.0f };
drop46.v[2] = { -0.55f, -1.2f, 1.0f, 1.0f };

drop47.v[0] = { -0.55f, -1.0f, 1.0f, 0.0f };
drop47.v[1] = { -0.6f, -1.0f, 0.0f, 0.0f };
drop47.v[2] = { -0.55f, -1.2f, 1.0f, 1.0f };

//капля 25
drop48.v[0] = { -0.5f, -1.3f, 0.0f, 1.0f };
drop48.v[1] = { -0.5f, -1.1f, 0.0f, 0.0f };
drop48.v[2] = { -0.45f, -1.3f, 1.0f, 1.0f };

drop49.v[0] = { -0.45f, -1.1f, 1.0f, 0.0f };
drop49.v[1] = { -0.5f, -1.1f, 0.0f, 0.0f };
drop49.v[2] = { -0.45f, -1.3f, 1.0f, 1.0f };

//===== мельница 1 (левая) =====
//добавляем треугольники
triangle millbase1, millbase2, blade_down1, blade_down2, blade_up1, blade_up2,
    blade_left1, blade_left2, blade_right1, blade_right2, platform_down1,
    platform_down2;

//мельница 1 основание
millbase1.v[0] = { -0.8f, -0.9f, 0.0f, 1.0f };
millbase1.v[1] = { -0.8f, -0.1f, 0.0f, 0.0f };
millbase1.v[2] = { -0.5f, -0.9f, 1.0f, 1.0f };

millbase2.v[0] = { -0.5f, -0.1f, 1.0f, 0.0f };
millbase2.v[1] = { -0.8f, -0.1f, 0.0f, 0.0f };
millbase2.v[2] = { -0.5f, -0.9f, 1.0f, 1.0f };

//мельница 1 нижняя лопасть
blade_down1.v[0] = { -0.7f, -0.6f, 0.0f, 1.0f };
blade_down1.v[1] = { -0.7f, -0.25f, 0.0f, 0.0f };
blade_down1.v[2] = { -0.6f, -0.6f, 1.0f, 1.0f };

blade_down2.v[0] = { -0.6f, -0.25f, 1.0f, 0.0f };
blade_down2.v[1] = { -0.7f, -0.25f, 0.0f, 0.0f };
blade_down2.v[2] = { -0.6f, -0.6f, 1.0f, 1.0f };

//мельница 1 верхняя лопасть
blade_up1.v[0] = { -0.7f, -0.25f, 0.0f, 1.0f };
blade_up1.v[1] = { -0.7f, 0.1f, 0.0f, 0.0f };
blade_up1.v[2] = { -0.6f, -0.25f, 1.0f, 1.0f };

blade_up2.v[0] = { -0.6f, 0.1f, 1.0f, 0.0f };
blade_up2.v[1] = { -0.7f, 0.1f, 0.0f, 0.0f };
blade_up2.v[2] = { -0.6f, -0.25f, 1.0f, 1.0f };

//мельница 1 правая лопасть
blade_right1.v[0] = { -0.65f, -0.3f, 1.0f, 0.0f };
blade_right1.v[1] = { -0.65f, -0.2f, 1.0f, 1.0f };
blade_right1.v[2] = { -0.3f, -0.3f, 0.0f, 0.0f };

blade_right2.v[0] = { -0.3f, -0.2f, 0.0f, 1.0f };
blade_right2.v[1] = { -0.65f, -0.2f, 1.0f, 1.0f };
blade_right2.v[2] = { -0.3f, -0.3f, 0.0f, 0.0f };

//мельница 1 левая лопасть
blade_left1.v[0] = { -1.0f, -0.3f, 1.0f, 0.0f };
blade_left1.v[1] = { -1.0f, -0.2f, 1.0f, 1.0f };
blade_left1.v[2] = { -0.65f, -0.3f, 0.0f, 0.0f };

blade_left2.v[0] = { -0.65f, -0.2f, 0.0f, 1.0f };
blade_left2.v[1] = { -1.0f, -0.2f, 1.0f, 1.0f };
blade_left2.v[2] = { -0.65f, -0.3f, 0.0f, 0.0f };

//мельница 1 платформа низ
platform_down1.v[0] = { -0.8f, -0.65f, 0.0f, 1.0f };
platform_down1.v[1] = { -0.8f, -0.55f, 0.0f, 0.0f };
platform_down1.v[2] = { -0.5f, -0.65f, 1.0f, 1.0f };

platform_down2.v[0] = { -0.5f, -0.55f, 1.0f, 0.0f };
platform_down2.v[1] = { -0.8f, -0.55f, 0.0f, 0.0f };
platform_down2.v[2] = { -0.5f, -0.65f, 1.0f, 1.0f };

//копии для врящения мельницы 1
triangle bl_up1, bl_up2;
triangle bl_down1, bl_down2;
triangle bl_right1, bl_right2;
triangle bl_left1, bl_left2;

triangle pl_down1, pl_down2;

//===== мельница 2 (правая) =====
//добавляем треугольники
triangle millbase1_r, millbase2_r, blade_down1_r, blade_down2_r, blade_up1_r,
    blade_up2_r, blade_left1_r, blade_left2_r, blade_right1_r, blade_right2_r,
    platform_down1_r, platform_down2_r;

//мельница 2 основание
millbase1_r.v[0] = { 0.8f, -0.9f, 0.0f, 1.0f };
millbase1_r.v[1] = { 0.8f, -0.1f, 0.0f, 0.0f };
millbase1_r.v[2] = { 0.5f, -0.9f, 1.0f, 1.0f };

millbase2_r.v[0] = { 0.5f, -0.1f, 1.0f, 0.0f };
millbase2_r.v[1] = { 0.8f, -0.1f, 0.0f, 0.0f };
millbase2_r.v[2] = { 0.5f, -0.9f, 1.0f, 1.0f };

//мельница 2 нижняя лопасть
blade_down1_r.v[0] = { 0.7f, -0.6f, 0.0f, 1.0f };
blade_down1_r.v[1] = { 0.7f, -0.25f, 0.0f, 0.0f };
blade_down1_r.v[2] = { 0.6f, -0.6f, 1.0f, 1.0f };

blade_down2_r.v[0] = { 0.6f, -0.25f, 1.0f, 0.0f };
blade_down2_r.v[1] = { 0.7f, -0.25f, 0.0f, 0.0f };
blade_down2_r.v[2] = { 0.6f, -0.6f, 1.0f, 1.0f };

//мельница 2 верхняя лопасть
blade_up1_r.v[0] = { 0.7f, -0.25f, 0.0f, 1.0f };
blade_up1_r.v[1] = { 0.7f, 0.1f, 0.0f, 0.0f };
blade_up1_r.v[2] = { 0.6f, -0.25f, 1.0f, 1.0f };

blade_up2_r.v[0] = { 0.6f, 0.1f, 1.0f, 0.0f };
blade_up2_r.v[1] = { 0.7f, 0.1f, 0.0f, 0.0f };
blade_up2_r.v[2] = { 0.6f, -0.25f, 1.0f, 1.0f };

//мельница 2 левая лопасть
blade_right1_r.v[0] = { 0.65f, -0.3f, 1.0f, 0.0f };
blade_right1_r.v[1] = { 0.65f, -0.2f, 1.0f, 1.0f };
blade_right1_r.v[2] = { 0.3f, -0.3f, 0.0f, 0.0f };

blade_right2_r.v[0] = { 0.3f, -0.2f, 0.0f, 1.0f };
blade_right2_r.v[1] = { 0.65f, -0.2f, 1.0f, 1.0f };
blade_right2_r.v[2] = { 0.3f, -0.3f, 0.0f, 0.0f };

//мельница 2 правая лопасть
blade_left1_r.v[0] = { 1.0f, -0.3f, 1.0f, 0.0f };
blade_left1_r.v[1] = { 1.0f, -0.2f, 1.0f, 1.0f };
blade_left1_r.v[2] = { 0.65f, -0.3f, 0.0f, 0.0f };

blade_left2_r.v[0] = { 0.65f, -0.2f, 0.0f, 1.0f };
blade_left2_r.v[1] = { 1.0f, -0.2f, 1.0f, 1.0f };
blade_left2_r.v[2] = { 0.65f, -0.3f, 0.0f, 0.0f };

//мельница 2 платформа низ
platform_down1_r.v[0] = { 0.5f, -0.65f, 0.0f, 1.0f };
platform_down1_r.v[1] = { 0.5f, -0.55f, 0.0f, 0.0f };
platform_down1_r.v[2] = { 0.8f, -0.65f, 1.0f, 1.0f };

platform_down2_r.v[0] = { 0.8f, -0.55f, 1.0f, 0.0f };
platform_down2_r.v[1] = { 0.5f, -0.55f, 0.0f, 0.0f };
platform_down2_r.v[2] = { 0.8f, -0.65f, 1.0f, 1.0f };

//копии для врящения мельницы 2
triangle bl_up1_r, bl_up2_r;
triangle bl_down1_r, bl_down2_r;
triangle bl_right1_r, bl_right2_r;
triangle bl_left1_r, bl_left2_r;

triangle pl_down1_r, pl_down2_r;

//===== мельница 3 (центр) =====
//добавляем треугольники
triangle millbase1_c, millbase2_c, blade_down1_c, blade_down2_c, blade_up1_c,
    blade_up2_c, blade_left1_c, blade_left2_c, blade_right1_c, blade_right2_c,
    platform_down1_c, platform_down2_c;

//мельница 3 основание
millbase1_c.v[0] = { 0.15f, -0.9f, 0.0f, 1.0f };
millbase1_c.v[1] = { 0.15f, -0.1f, 0.0f, 0.0f };
millbase1_c.v[2] = { -0.15f, -0.9f, 1.0f, 1.0f };

millbase2_c.v[0] = { -0.15f, -0.1f, 1.0f, 0.0f };
millbase2_c.v[1] = { 0.15f, -0.1f, 0.0f, 0.0f };
millbase2_c.v[2] = { -0.15f, -0.9f, 1.0f, 1.0f };

//мельница 3 нижняя лопасть
blade_down1_c.v[0] = { -0.05f, -0.6f, 0.0f, 1.0f };
blade_down1_c.v[1] = { -0.05f, -0.25f, 0.0f, 0.0f };
blade_down1_c.v[2] = { 0.05f, -0.6f, 1.0f, 1.0f };

blade_down2_c.v[0] = { 0.05f, -0.25f, 1.0f, 0.0f };
blade_down2_c.v[1] = { -0.05f, -0.25f, 0.0f, 0.0f };
blade_down2_c.v[2] = { 0.05f, -0.6f, 1.0f, 1.0f };

//мельница 3 верхняя лопасть
blade_up1_c.v[0] = { 0.05f, -0.25f, 0.0f, 1.0f };
blade_up1_c.v[1] = { 0.05f, 0.1f, 0.0f, 0.0f };
blade_up1_c.v[2] = { -0.05f, -0.25f, 1.0f, 1.0f };

blade_up2_c.v[0] = { -0.05f, 0.1f, 1.0f, 0.0f };
blade_up2_c.v[1] = { 0.05f, 0.1f, 0.0f, 0.0f };
blade_up2_c.v[2] = { -0.05f, -0.25f, 1.0f, 1.0f };

//мельница 3 левая лопасть
blade_right1_c.v[0] = { 0.0f, -0.3f, 1.0f, 0.0f };
blade_right1_c.v[1] = { 0.0f, -0.2f, 1.0f, 1.0f };
blade_right1_c.v[2] = { -0.35f, -0.3f, 0.0f, 0.0f };

blade_right2_c.v[0] = { -0.35f, -0.2f, 0.0f, 1.0f };
blade_right2_c.v[1] = { 0.0f, -0.2f, 1.0f, 1.0f };
blade_right2_c.v[2] = { -0.35f, -0.3f, 0.0f, 0.0f };

//мельница 3 правая лопасть
blade_left1_c.v[0] = { 0.35f, -0.3f, 1.0f, 0.0f };
blade_left1_c.v[1] = { 0.35f, -0.2f, 1.0f, 1.0f };
blade_left1_c.v[2] = { 0.0f, -0.3f, 0.0f, 0.0f };

blade_left2_c.v[0] = { 0.0f, -0.2f, 0.0f, 1.0f };
blade_left2_c.v[1] = { 0.35f, -0.2f, 1.0f, 1.0f };
blade_left2_c.v[2] = { 0.0f, -0.3f, 0.0f, 0.0f };

//мельница 3 платформа низ
platform_down1_c.v[0] = { -0.15f, -0.65f, 0.0f, 1.0f };
platform_down1_c.v[1] = { -0.15f, -0.55f, 0.0f, 0.0f };
platform_down1_c.v[2] = { 0.15f, -0.65f, 1.0f, 1.0f };

platform_down2_c.v[0] = { 0.15f, -0.55f, 1.0f, 0.0f };
platform_down2_c.v[1] = { -0.15f, -0.55f, 0.0f, 0.0f };
platform_down2_c.v[2] = { 0.15f, -0.65f, 1.0f, 1.0f };

//копии для врящения мельницы 3
triangle bl_up1_c, bl_up2_c;
triangle bl_down1_c, bl_down2_c;
triangle bl_right1_c, bl_right2_c;
triangle bl_left1_c, bl_left2_c;

triangle pl_down1_c, pl_down2_c;

//===== фон =====
triangle background, background1;

background.v[0] = { -1.0f, -1.0f, 0.0f, 1.0f };
background.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
background.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

background1.v[0] = { 1.0f, 1.0f, 1.0f, 0.0f };
background1.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
background1.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

//===== главное окно =====
triangle title_window, title_window1;

title_window.v[0] = { -1.0f, -1.0f, 0.0f, 1.0f };
title_window.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
title_window.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

title_window1.v[0] = { 1.0f, 1.0f, 1.0f, 0.0f };
title_window1.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
title_window1.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

//===== окно паузы =====
triangle pause_window, pause_window1;

pause_window.v[0] = { -1.0f, -1.0f, 0.0f, 1.0f };
pause_window.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
pause_window.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

pause_window1.v[0] = { 1.0f, 1.0f, 1.0f, 0.0f };
pause_window1.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
pause_window1.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

//===== окно game over =====
triangle over_window, over_window1;

over_window.v[0] = { -1.0f, -1.0f, 0.0f, 1.0f };
over_window.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
over_window.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

over_window1.v[0] = { 1.0f, 1.0f, 1.0f, 0.0f };
over_window1.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
over_window1.v[2] = { 1.0f, -1.0f, 1.0f, 1.0f };

//мельница в главном окне
//===== мельница 1 (левая) =====
//добавляем треугольники
triangle title_millbase1, title_millbase2, title_blade_down1, title_blade_down2,
    title_blade_up1, title_blade_up2, title_blade_left1, title_blade_left2,
    title_blade_right1, title_blade_right2;
//мельница 1 основание
title_millbase1.v[0] = { -0.8f, -0.9f, 0.0f, 1.0f };
title_millbase1.v[1] = { -0.8f, -0.1f, 0.0f, 0.0f };
title_millbase1.v[2] = { -0.5f, -0.9f, 1.0f, 1.0f };

title_millbase2.v[0] = { -0.5f, -0.1f, 1.0f, 0.0f };
title_millbase2.v[1] = { -0.8f, -0.1f, 0.0f, 0.0f };
title_millbase2.v[2] = { -0.5f, -0.9f, 1.0f, 1.0f };

//мельница 1 нижняя лопасть
title_blade_down1.v[0] = { -0.7f, -0.6f, 0.0f, 1.0f };
title_blade_down1.v[1] = { -0.7f, -0.25f, 0.0f, 0.0f };
title_blade_down1.v[2] = { -0.6f, -0.6f, 1.0f, 1.0f };

title_blade_down2.v[0] = { -0.6f, -0.25f, 1.0f, 0.0f };
title_blade_down2.v[1] = { -0.7f, -0.25f, 0.0f, 0.0f };
title_blade_down2.v[2] = { -0.6f, -0.6f, 1.0f, 1.0f };

//мельница 1 верхняя лопасть
title_blade_up1.v[0] = { -0.7f, -0.25f, 0.0f, 1.0f };
title_blade_up1.v[1] = { -0.7f, 0.1f, 0.0f, 0.0f };
title_blade_up1.v[2] = { -0.6f, -0.25f, 1.0f, 1.0f };

title_blade_up2.v[0] = { -0.6f, 0.1f, 1.0f, 0.0f };
title_blade_up2.v[1] = { -0.7f, 0.1f, 0.0f, 0.0f };
title_blade_up2.v[2] = { -0.6f, -0.25f, 1.0f, 1.0f };

//мельница 1 правая лопасть
title_blade_right1.v[0] = { -0.65f, -0.3f, 1.0f, 0.0f };
title_blade_right1.v[1] = { -0.65f, -0.2f, 1.0f, 1.0f };
title_blade_right1.v[2] = { -0.3f, -0.3f, 0.0f, 0.0f };

title_blade_right2.v[0] = { -0.3f, -0.2f, 0.0f, 1.0f };
title_blade_right2.v[1] = { -0.65f, -0.2f, 1.0f, 1.0f };
title_blade_right2.v[2] = { -0.3f, -0.3f, 0.0f, 0.0f };

//мельница 1 левая лопасть
title_blade_left1.v[0] = { -1.0f, -0.3f, 1.0f, 0.0f };
title_blade_left1.v[1] = { -1.0f, -0.2f, 1.0f, 1.0f };
title_blade_left1.v[2] = { -0.65f, -0.3f, 0.0f, 0.0f };

title_blade_left2.v[0] = { -0.65f, -0.2f, 0.0f, 1.0f };
title_blade_left2.v[1] = { -1.0f, -0.2f, 1.0f, 1.0f };
title_blade_left2.v[2] = { -0.65f, -0.3f, 0.0f, 0.0f };

//копии для врящения мельницы в главном огне
triangle title_bl_up1, title_bl_up2;
triangle title_bl_down1, title_bl_down2;
triangle title_bl_right1, title_bl_right2;
triangle title_bl_left1, title_bl_left2;

//таймер геометрия
triangle seconds, seconds1, seconds2, seconds3;
triangle minutes, minutes1, minutes2, minutes3;
triangle dot, dot1;

//точка
dot.v[0] = { -0.94f, 0.8f, 0.0f, 1.0f };
dot.v[1] = { -0.94f, 1.0f, 0.0f, 0.0f };
dot.v[2] = { -0.89f, 0.8f, 1.0f, 1.0f };

dot1.v[0] = { -0.89f, 1.0f, 1.0f, 0.0f };
dot1.v[1] = { -0.94f, 1.0f, 0.0f, 0.0f };
dot1.v[2] = { -0.89f, 0.8f, 1.0f, 1.0f };

//секунды
seconds.v[0] = { -0.84f, 0.8f, 0.0f, 1.0f };
seconds.v[1] = { -0.84f, 1.0f, 0.0f, 0.0f };
seconds.v[2] = { -0.79f, 0.8f, 1.0f, 1.0f };

seconds1.v[0] = { -0.79f, 1.0f, 1.0f, 0.0f };
seconds1.v[1] = { -0.84f, 1.0f, 0.0f, 0.0f };
seconds1.v[2] = { -0.79f, 0.8f, 1.0f, 1.0f };

seconds2.v[0] = { -0.89f, 0.8f, 0.0f, 1.0f };
seconds2.v[1] = { -0.89f, 1.0f, 0.0f, 0.0f };
seconds2.v[2] = { -0.84f, 0.8f, 1.0f, 1.0f };

seconds3.v[0] = { -0.844f, 1.0f, 1.0f, 0.0f };
seconds3.v[1] = { -0.89f, 1.0f, 0.0f, 0.0f };
seconds3.v[2] = { -0.84f, 0.8f, 1.0f, 1.0f };

//минуты
minutes.v[0] = { -0.95f, 0.8f, 0.0f, 1.0f };
minutes.v[1] = { -0.95f, 1.0f, 0.0f, 0.0f };
minutes.v[2] = { -0.9f, 0.8f, 1.0f, 1.0f };

minutes1.v[0] = { -0.9f, 1.0f, 1.0f, 0.0f };
minutes1.v[1] = { -0.95f, 1.0f, 0.0f, 0.0f };
minutes1.v[2] = { -0.9f, 0.8f, 1.0f, 1.0f };

minutes2.v[0] = { -1.0f, 0.8f, 0.0f, 1.0f };
minutes2.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
minutes2.v[2] = { -0.95f, 0.8f, 1.0f, 1.0f };

minutes3.v[0] = { -0.95f, 1.0f, 1.0f, 0.0f };
minutes3.v[1] = { -1.0f, 1.0f, 0.0f, 0.0f };
minutes3.v[2] = { -0.95f, 0.8f, 1.0f, 1.0f };

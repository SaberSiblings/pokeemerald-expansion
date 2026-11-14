OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_OLDALE_TOWN_SURSKIT, OldaleTown_House1_EventScript_Received
	msgbox OldaleTown_House1_Text_Surskit, MSGBOX_DEFAULT
	special IsSurskitInParty
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_House1_EventScript_NoSurskit
	closemessage
	playse SE_PIN
	applymovement LOCALID_SURSKIT_WOMAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SURSKIT_WOMAN, Common_Movement_Delay48
	waitmovement 0
	msgbox OldaleTown_House1_Text_Success, MSGBOX_DEFAULT
	giveitem ITEM_TM_STRUGGLE_BUG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OLDALE_TOWN_SURSKIT
	msgbox OldaleTown_House1_Text_StruggleBug, MSGBOX_DEFAULT
	release
	end

OldaleTown_House1_EventScript_Received::
	msgbox OldaleTown_House1_Text_StruggleBug, MSGBOX_DEFAULT
	release
	end

OldaleTown_House1_EventScript_NoSurskit::
	release
	end

OldaleTown_House1_Text_Surskit:
	.string "Are you aware of a Pokémon\n"
	.string "known as Surskit?\p"
	.string "It's so light that it can\n"
	.string "skate on the surface of water.\p"
	.string "I'd love to see one,\n"
	.string "if you wouldn't mind catching one\l"
	.string "and bringing it to me.$"

OldaleTown_House1_Text_Success::
	.string "Oh? Is that a Surskit\n"
	.string "in your party?\p"
	.string "Aww! Isn't it adorable?\n"
	.string "What a darling thing!\p"
	.string "Thank you for taking the time\n"
	.string "to catch one for me!\p"
	.string "Here's a token of my gratitude.$"

OldaleTown_House1_Text_StruggleBug::
	.string "Feel free to teach that\n"
	.string "to your Surskit.\p"
	.string "Technical machines are\n"
	.string "reusable, so use them as much\l"
	.string "as you want!$"

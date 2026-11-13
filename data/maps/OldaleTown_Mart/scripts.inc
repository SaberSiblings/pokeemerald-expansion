OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	msgbox OldaleTown_Mart_Text_Feral, MSGBOX_DEFAULT
	/*message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT*/
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	//goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "You should look at the stats of\n"
	.string "your Pokémon closely.\p"
	.string "The more effort it puts in over\n"
	.string "time, the more you can have it\l"
	.string "use that effort to become strong.\p"
	.string "The teacher at the Trainer School\n"
	.string "in Rustboro has notes on it.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "I'm going to buy a bunch of POKé BALLS\n"
	.string "and catch a bunch of Pokémon!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "I don't have any badges, so the Poké\n"
	.string "Mart won't sell me good items.\p"
	.string "More badges means more respect, which\n"
	.string "gets you the good stuff.$"

OldaleTown_Mart_Text_Feral:
	.string "The wild Pokémon in this region\n"
	.string "are particularly feral.\p"
	.string "I don't think I've ever\n"
	.string "seen a Normal-type Pokémon\l"
	.string "among Hoenn's wildlife.\p"
	.string "The Trainer School in Rustboro\n"
	.string "just gave a class over this new\l"
	.string "“Beast” type.$"

OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "When Pokémon battle, they eventually\n"
	.string "level up and become stronger.\p"
	.string "With experience comes power, but\n"
	.string "with great power comes responsibility.\p"
	.string "…Did I say something?$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Did you come from Littleroot?\n"
	.string "It's a nice place, but you won't\l"
	.string "find any challenge there.\p"
	.string "If you wish to push yourself,\n"
	.string "you'll have to explore further\l"
	.string "than these small towns.$"


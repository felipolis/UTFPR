class_name MainMenu
extends Control

@onready var background_terrain = $"background/01/texture"
@onready var transition = $transition
@onready var current_value = $score/current_container/current_value
@onready var record_value = $score/record_container/record_value


# Called when the node enters the scene tree for the first time.
func _ready():
	current_value.text = str("%06d" % Global.player_score)
	record_value.text = str("%06d" % Global.player_record)
	
	var current_level = Global.get_last_level()
	if background_terrain != null:
		if current_level <= 5:
			background_terrain.texture = ResourceLoader.load("res://src/assets/tilesets/1 - Grassland/background/1 - Foreground_scenery.png")
		else:
			background_terrain.texture = ResourceLoader.load("res://src/assets/tilesets/2 - Mushroom World/background/1 - Foreground_scenery.png")
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
	
func _on_new_game_button_pressed():
	# Reseta todo o jogo
	Global._reset_game()
	
	# Inicia o jogo
	transition.visible = true
	transition.change_scene("res://src/levels/level_01.tscn")
	

func _on_select_level_button_pressed():
	transition.visible = true
	transition.change_scene("res://src/interfaces/select_level.tscn")


func _on_credits_button_pressed():
	transition.visible = true
	transition.change_scene("res://src/interfaces/credits.tscn")

func _on_quit_button_pressed():
	get_tree().quit()

func _on_controls_button_pressed():
	transition.visible = true
	transition.change_scene("res://src/interfaces/controls.tscn")

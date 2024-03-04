extends Control

@onready var levels := $levels
@onready var background_terrain = $"background/01/texture"
@onready var transition = $transition

var current_level

# Called when the node enters the scene tree for the first time.
func _ready():
	current_level = Global.get_last_level()
	
	if levels != null:
		# Obtenha o número de filhos do nó "level"
		var num_children = levels.get_child_count()
		
		
		
		# Itere sobre todos os filhos do nó "level"
		for i in num_children:
			var child = levels.get_child(i)
			child.disabled = not Global.levels[i]
			if i == current_level - 1:
				child.modulate = "ffff00"
	
	if background_terrain != null:
		if current_level <= 5:
			background_terrain.texture = ResourceLoader.load("res://src/assets/tilesets/1 - Grassland/background/1 - Foreground_scenery.png")
		else:
			background_terrain.texture = ResourceLoader.load("res://src/assets/tilesets/2 - Mushroom World/background/1 - Foreground_scenery.png")
		


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_back_pressed():
	transition.visible = true
	transition.change_scene("res://src/interfaces/main_menu.tscn")

func _on_level_01_pressed():
	if current_level == 1:
		transition.visible = true
		transition.change_scene("res://src/levels/level_01.tscn")


func _on_level_02_pressed():
	if current_level == 2:
		transition.visible = true
		transition.change_scene("res://src/levels/level_02.tscn")


func _on_level_03_pressed():
	if current_level == 3:
		transition.visible = true
		transition.change_scene("res://src/levels/level_03.tscn")


func _on_level_04_pressed():
	if current_level == 4:
		transition.visible = true
		transition.change_scene("res://src/levels/level_04.tscn")


func _on_level_05_pressed():
	if current_level == 5:
		transition.visible = true
		transition.change_scene("res://src/levels/level_05.tscn")


func _on_level_06_pressed():
	if current_level == 6:
		transition.visible = true
		transition.change_scene("res://src/levels/level_06.tscn")


func _on_level_07_pressed():
	if current_level == 7:
		transition.visible = true
		transition.change_scene("res://src/levels/level_07.tscn")


func _on_level_08_pressed():
	if current_level == 8:
		transition.visible = true
		transition.change_scene("res://src/levels/level_08.tscn")


func _on_level_09_pressed():
	if current_level == 9:
		transition.visible = true
		transition.change_scene("res://src/levels/level_09.tscn")


func _on_level_10_pressed():
	if current_level == 10:
		transition.visible = true
		transition.change_scene("res://src/levels/level_10.tscn")

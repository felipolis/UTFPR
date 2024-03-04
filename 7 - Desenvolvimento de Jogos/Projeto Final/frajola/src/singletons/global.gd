extends Node

var current_scene = null
var levels = [true, false, false, false, false, false, false, false, false, false]

var player_life = 7
var player_bullets = 0
var player_score = 0
var player_record = 0

var backup_lives = 0
var backup_bullets = 0
var backup_score = 0

func _ready():
	var root = get_tree().root
	current_scene = root.get_child(root.get_child_count() - 1)

func _reset_game():
	levels = [true, false, false, false, false, false, false, false, false, false]
	player_life = 7
	player_bullets = 0
	player_score = 0
	
	backup_lives = 0
	backup_bullets = 0
	backup_score = 0

func get_backup():
	player_life = backup_lives
	player_bullets = backup_bullets
	player_score = backup_score

func set_backup():
	backup_lives = player_life
	backup_bullets = player_bullets
	backup_score = player_score
	for level in levels.size():
		if not levels[level]:
			levels[level] = true
			break
	
func has_finished():
	_reset_game()
	player_record = backup_score

func goto_scene(path):
	call_deferred("_deferred_goto_scene", path)

func _deferred_goto_scene(path):
	# It is now safe to remove the current scene
	current_scene.free()

	# Load the new scene.
	var s = ResourceLoader.load(path)

	# Instance the new scene.
	current_scene = s.instantiate()

	# Add it to the active scene, as child of root.
	get_tree().root.add_child(current_scene)

	# Optionally, to make it compatible with the SceneTree.change_scene_to_file() API.
	get_tree().current_scene = current_scene

func get_last_level():
	for level in levels.size():
		if levels[level] == false:
			return level
	return 10

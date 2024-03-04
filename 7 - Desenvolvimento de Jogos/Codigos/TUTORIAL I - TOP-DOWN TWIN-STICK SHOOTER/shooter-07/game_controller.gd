class_name GameController
extends Node

var _player: Player
var _camera: Camera2D
var _keys_ui: TextureRect
var _Keys: int  = 0
var _keys_height: float

# PRIVATE METHODS
############################################


# PUBLIC METHODS
############################################
func init(player, camera) -> void:
	_player = player
	_camera = camera
	get_tree().call_group("generator", "set_player", _player)


func get_camera() -> Camera2D:
	return _camera

class_name GameController
extends Node2D

@onready var _player: Player = $Player

func _ready() -> void:
	get_tree().call_group("enemy", "set_player", _player)

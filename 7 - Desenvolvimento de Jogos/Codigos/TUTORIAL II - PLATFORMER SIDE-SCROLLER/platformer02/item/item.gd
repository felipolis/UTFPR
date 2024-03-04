extends Area2D


@onready var _player: AnimationPlayer = $AnimationPlayer

# create an animation offset by x global_position
func _ready() -> void:
	var offset: int = int(global_position.x) % 10
	_player.seek( (_player.current_animation_length / 10) * offset)

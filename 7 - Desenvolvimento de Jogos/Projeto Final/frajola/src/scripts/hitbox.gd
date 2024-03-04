extends Area2D

@onready var atack_sfx = $atackSFX


func _on_body_entered(body):
	if body.name == "frajola":
		owner.life -= 1
		atack_sfx.play()
		if owner.get_groups()[0] == 'boss':
			body.velocity.y = body.JUMP_FORCE
			body.velocity.x = body.JUMP_FORCE * 4 * (owner.direction * -1)
		else:
			body.velocity.y = body.JUMP_FORCE
		if owner.life <= 0:
			owner.anim.play("die")
		else:
			owner.anim.play("hurt")
	elif body.name == "ball":
		owner.life -= 1
		if owner.life <= 0:
			owner.anim.play("die")
		else:
			owner.anim.play("hurt")
		body.queue_free()
	

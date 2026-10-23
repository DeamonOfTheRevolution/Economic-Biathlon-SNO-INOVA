extends CharacterBody2D

@onready var _animation_player = $AnimatedSprite2D
const walk_speed = 300.0

func _physics_process(delta):
	if Global.player_walk1 or Global.player_walk2:
		_animation_player.play("run")
		velocity.x = 1 * walk_speed
	else:
		velocity.x = 0
		if Global.player_down_anim:
			var frames= $AnimatedSprite2D.frame
			_animation_player.play("down")
			if frames==2:
				Global.player_down=true
				Global.player_down_anim=false
		if Global.player_down:
			_animation_player.play("down_idle")
			if Global.answers == 6:
				Global.player_up_anim=true
				Global.player_down=false
		if Global.player_up_anim:
			var frames= $AnimatedSprite2D.frame
			_animation_player.play("up")
			if frames==2:
				Global.player_walk2=true
				Global.player_up_anim=false

	move_and_slide()

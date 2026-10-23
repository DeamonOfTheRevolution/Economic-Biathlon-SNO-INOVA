extends Node2D


func _on_g_point_button_answer_1_pressed():
	Global.answers += 1
	$"Прямо/Sprite-0007".modulate = Color(1, 1, 1)
func _on_g_point_button_answer_2_pressed():
	Global.answers += 1
	$"Прямо/Sprite-0007".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_3_pressed():
	Global.answers += 1
	$"Прямо/Sprite-0007".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_4_pressed():
	Global.answers += 1
	$"Прямо/Sprite-0007".modulate = Color(1, 0, 0)


func _on_g_point_button_answer_11_pressed():
	if Global.answers == 1:
		Global.answers += 1
		$"Прямо/Sprite-0008".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_21_pressed():
	if Global.answers == 1:
		Global.answers += 1
		$"Прямо/Sprite-0008".modulate = Color(1, 1, 1)
func _on_g_point_button_answer_31_pressed():
	if Global.answers == 1:
		Global.answers += 1
		$"Прямо/Sprite-0008".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_41_pressed():
	if Global.answers == 1:
		Global.answers += 1
		$"Прямо/Sprite-0008".modulate = Color(1, 0, 0)


func _on_g_point_button_answer_12_pressed():
	if Global.answers == 2:
		Global.answers += 1
		$"Прямо/Sprite-0009".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_22_pressed():
	if Global.answers == 2:
		Global.answers += 1
		$"Прямо/Sprite-0009".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_32_pressed():
	if Global.answers == 2:
		Global.answers += 1
		$"Прямо/Sprite-0009".modulate = Color(1, 1, 1)
func _on_g_point_button_answer_42_pressed():
	if Global.answers == 2:
		Global.answers += 1
		$"Прямо/Sprite-0009".modulate = Color(1, 0, 0)


func _on_g_point_button_answer_13_pressed():
	if Global.answers == 3:
		Global.answers += 1
		$"Прямо/Sprite-0010".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_23_pressed():
	if Global.answers == 3:
		Global.answers += 1
		$"Прямо/Sprite-0010".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_33_pressed():
	if Global.answers == 3:
		Global.answers += 1
		$"Прямо/Sprite-0010".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_43_pressed():
	if Global.answers == 3:
		Global.answers += 1
		$"Прямо/Sprite-0010".modulate = Color(1, 1, 1)


func _on_g_point_button_answer_14_pressed():
	if Global.answers == 4:
		Global.answers += 1
		$"Прямо/Sprite-0011".modulate = Color(1, 1, 1)
func _on_g_point_button_answer_24_pressed():
	if Global.answers == 4:
		Global.answers += 1
		$"Прямо/Sprite-0011".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_34_pressed():
	if Global.answers == 4:
		Global.answers += 1
		$"Прямо/Sprite-0011".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_44_pressed():
	if Global.answers == 4:
		Global.answers += 1
		$"Прямо/Sprite-0011".modulate = Color(1, 0, 0)


func _on_g_point_button_answer_15_pressed():
	if Global.answers == 5:
		Global.answers += 1
		$"Прямо/Sprite-0012".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_25_pressed():
	if Global.answers == 5:
		Global.answers += 1
		$"Прямо/Sprite-0012".modulate = Color(1, 1, 1)
func _on_g_point_button_answer_35_pressed():
	if Global.answers == 5:
		Global.answers += 1
		$"Прямо/Sprite-0012".modulate = Color(1, 0, 0)
func _on_g_point_button_answer_45_pressed():
	if Global.answers == 5:
		Global.answers += 1
		$"Прямо/Sprite-0012".modulate = Color(1, 0, 0)

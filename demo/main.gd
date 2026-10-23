extends Node2D
var points = 0
var quest_dict = {
	"В чём заключается основная проблема которую изучает экономи ческая наука" : ["Ограниченность экономических ресурсов и неограниченность человеческих
желаний и потребностей порождает фундаментальную экономическую проблему
выбора направлений действий человека и способов распределения ограниченных
ресурсов между различными конкурирующ ими целями.", "Богатство общества и закономерности его формирования в условиях когда
интересы отдельных экономических субъектов, государства, фирм и населения не
совпадают и вступают в противоречие друг с другом."],
	"Что понимается под понятием экономическая культура личности?" : ["Знание каждым гражданином страны экономических законов, правил и норм
действующих в каждой конкретной стране.", "Это единство сознания и практической деятельности, определяющее
направленность экономической активности человека в процессе производства,
распределения и потребления материальных благ и услуг.Экономическая
культура индивида(личности) личности), это совокупность его экономических знаний,
взглядов, убеждений, исторического опыта."],
	"Располагаемый доход человека это?" : ["Номинальный доход за вычетом налогов и обязательных платежей.", "Реальный доход человека с учётом роста цен (инфляции)."],
	"Что понимается под словом налог?" : ["Платёж в пользу государства при покупке какого либо товара.", "Обязательный индивидуальный безвозмездный платёж взымаемый с физического или юридического лица
	в целях финансового обеспечения физического или юридического лица в целях финансового обеспечения
деятельности государства. деятельности государства."],
	"Семейный бюджет это?" : ["План доходов и расходов семьи за определённый период времени.", "Сумма доходов семьи за определённый период времени."]
}

func _ready():
	$Tspeed.hide()
	$Fspeed.hide()
	$TimeRemaining.hide()

func _process(delta):
	$TimeRemaining.text = "%s" % roundf($Quest_Timer.time_left)
	
func _on_quest_timer_timeout():
	$Tspeed.hide()
	$Fspeed.hide()
	$TimeRemaining.hide()
	$Wait_Timer.start()
	
func _on_wait_timer_timeout():
	if quest_dict.is_empty():
		$Tspeed.hide()
		$Fspeed.hide()
		$TimeRemaining.hide()
		if points == 0:
			get_tree().change_scene_to_file("res://demo_w_end.tscn")
		if points > 0 and points < 5:
			get_tree().change_scene_to_file("res://demo_n_end.tscn")
		if points == 5:
			get_tree().change_scene_to_file("res://demo_b_end.tscn")
	else:
		var selected_question = randi() % quest_dict.size()
		var question = quest_dict.keys()[selected_question]
		var answers = quest_dict[question]
		$Tspeed.text = answers[0]
		$Fspeed.text = answers[1]
		quest_dict.erase(question)
		$Fspeed.show()
		$Tspeed.show()
		$Quest_Timer.start()
		$TimeRemaining.show()

func _on_fspeed_pressed():
	$Tspeed.hide()
	$Fspeed.hide()
	$Quest_Timer.stop()
	$Wait_Timer.start()

func _on_tspeed_pressed():
	$Tspeed.hide()
	$Fspeed.hide()
	$Quest_Timer.stop()
	$Wait_Timer.start()
	points += 1

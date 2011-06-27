all:monkeyrunner monkeyrecoder

monkeyrunner:
	monkeyrunner example_monkeyrunner.py

monkeyrecoder:
	monkeyrunner example_monkeyrunner_recoder.py

monkeyrunner.py:
	igawk -f auto_runnner/gen_monkey_script.awk monkey_rec_out.mr > body_script.py
	cat auto_runnner/head_sclipt.py body_script.py auto_runnner/footer_sclipt.py > monkeyrunner.py

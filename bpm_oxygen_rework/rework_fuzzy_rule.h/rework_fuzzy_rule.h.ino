 //rule1
  FuzzyRuleAntecedent *rileks_ganyaman_1 = new FuzzyRuleAntecedent();
  rileks_ganyaman_1->joinWithAND(rileks, ganyaman);

  FuzzyRuleAntecedent *a1_relax = new FuzzyRuleAntecedent();
  a1_relax->joinSingle(relax);

  FuzzyRuleAntecedent *rileks_ganyaman_relax_1 = new FuzzyRuleAntecedent();
  rileks_ganyaman_relax_1->joinWithAND(rileks_ganyaman_1, a1_relax);

  FuzzyRuleConsequent *a_1 = new FuzzyRuleConsequent();
  a_1->addOutput(a);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, rileks_ganyaman_relax_1, a_1);
  fuzzy->addFuzzyRule(fuzzyRule1);
  //


  //rule2
  FuzzyRuleAntecedent *rileks_ganyaman_2 = new FuzzyRuleAntecedent();
  rileks_ganyaman_2->joinWithAND(rileks, ganyaman);

  FuzzyRuleAntecedent *a1_chill = new FuzzyRuleAntecedent();
  a1_chill->joinSingle(chill);

  FuzzyRuleAntecedent *rileks_ganyaman_chill_2 = new FuzzyRuleAntecedent();
  rileks_ganyaman_chill_2->joinWithAND(rileks_ganyaman_2, a1_chill);

  FuzzyRuleConsequent *a_2 = new FuzzyRuleConsequent();
  a_2->addOutput(a);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, rileks_ganyaman_chill_2, a_2);
  fuzzy->addFuzzyRule(fuzzyRule2);
  //
  
  //rule3
  FuzzyRuleAntecedent *rileks_ganyaman_3 = new FuzzyRuleAntecedent();
  rileks_ganyaman_3->joinWithAND(rileks, ganyaman);

  FuzzyRuleAntecedent *s1_worry = new FuzzyRuleAntecedent();
  s1_worry->joinSingle(worry);

  FuzzyRuleAntecedent *rileks_ganyaman_worry_3 = new FuzzyRuleAntecedent();
  rileks_ganyaman_worry_3->joinWithAND(rileks_ganyaman_3, s1_worry);

  FuzzyRuleConsequent *s_3 = new FuzzyRuleConsequent();
  s_3->addOutput(s);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, rileks_ganyaman_worry_3, s_3);
  fuzzy->addFuzzyRule(fuzzyRule3);
  //
  
  //rule4
  FuzzyRuleAntecedent *rileks_ganyaman_4 = new FuzzyRuleAntecedent();
  rileks_ganyaman_4->joinWithAND(rileks, ganyaman);

  FuzzyRuleAntecedent *s1_nervous = new FuzzyRuleAntecedent();
  s1_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *rileks_ganyaman_nervous_4 = new FuzzyRuleAntecedent();
  rileks_ganyaman_nervous_4->joinWithAND(rileks_ganyaman_4, s1_nervous);

  FuzzyRuleConsequent *s_4 = new FuzzyRuleConsequent();
  s_4->addOutput(s);

  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, rileks_ganyaman_nervous_4, s_4);
  fuzzy->addFuzzyRule(fuzzyRule4);
  //
  
  //rule5 
  FuzzyRuleAntecedent *rileks_cemas_5 = new FuzzyRuleAntecedent();
  rileks_cemas_5->joinWithAND(rileks, cemas);

  FuzzyRuleAntecedent *c1_relax = new FuzzyRuleAntecedent();
  c1_relax->joinSingle(relax);

  FuzzyRuleAntecedent *rileks_cemas_relax_5 = new FuzzyRuleAntecedent();
  rileks_cemas_relax_5->joinWithAND(rileks_cemas_5, c1_relax);

  FuzzyRuleConsequent *c_5 = new FuzzyRuleConsequent();
  c_5->addOutput(c);

  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, rileks_cemas_relax_5, c_5);
  fuzzy->addFuzzyRule(fuzzyRule5);
  //
  
  //rule6
  FuzzyRuleAntecedent *rileks_cemas_6 = new FuzzyRuleAntecedent();
  rileks_cemas_6->joinWithAND(rileks, cemas);

  FuzzyRuleAntecedent *c1_chill = new FuzzyRuleAntecedent();
  c1_chill->joinSingle(chill);

  FuzzyRuleAntecedent *rileks_cemas_chill_6 = new FuzzyRuleAntecedent();
  rileks_cemas_chill_6->joinWithAND(rileks_cemas_6, c1_chill);

  FuzzyRuleConsequent *c_6 = new FuzzyRuleConsequent();
  c_6->addOutput(c);

  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, rileks_cemas_chill_6, c_6);
  fuzzy->addFuzzyRule(fuzzyRule6);
  //
  
  //rule7
  FuzzyRuleAntecedent *rileks_cemas_7 = new FuzzyRuleAntecedent();
  rileks_cemas_7->joinWithAND(rileks, cemas);

  FuzzyRuleAntecedent *a1_worry = new FuzzyRuleAntecedent();
  a1_worry->joinSingle(worry);

  FuzzyRuleAntecedent *rileks_cemas_worry_7 = new FuzzyRuleAntecedent();
  rileks_cemas_worry_7->joinWithAND(rileks_cemas_7, a1_worry);

  FuzzyRuleConsequent *a_7 = new FuzzyRuleConsequent();
  a_7->addOutput(a);

  FuzzyRule *fuzzyRule7 = new FuzzyRule(7, rileks_cemas_worry_7, a_7);
  fuzzy->addFuzzyRule(fuzzyRule7);
  //
  
  //rule8
  FuzzyRuleAntecedent *rileks_cemas_8 = new FuzzyRuleAntecedent();
  rileks_cemas_8->joinWithAND(rileks, cemas);

  FuzzyRuleAntecedent *s2_nervous = new FuzzyRuleAntecedent();
  s2_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *rileks_cemas_nervous_8 = new FuzzyRuleAntecedent();
  rileks_cemas_nervous_8->joinWithAND(rileks_cemas_8, s2_nervous);

  FuzzyRuleConsequent *s_8 = new FuzzyRuleConsequent();
  s_8->addOutput(s);

  FuzzyRule *fuzzyRule8 = new FuzzyRule(8, rileks_cemas_nervous_8, s_8);
  fuzzy->addFuzzyRule(fuzzyRule8);
  //  
  
  //rule9
  FuzzyRuleAntecedent *rileks_tenang_9 = new FuzzyRuleAntecedent();
  rileks_tenang_9->joinWithAND(rileks, tenang);

  FuzzyRuleAntecedent *r1_relax = new FuzzyRuleAntecedent();
  r1_relax->joinSingle(relax);

  FuzzyRuleAntecedent *rileks_tenang_relax_9 = new FuzzyRuleAntecedent();
  rileks_tenang_relax_9->joinWithAND(rileks_tenang_9, r1_relax);

  FuzzyRuleConsequent *r_9 = new FuzzyRuleConsequent();
  r_9->addOutput(r);

  FuzzyRule *fuzzyRule9 = new FuzzyRule(9, rileks_tenang_relax_9, r_9);
  fuzzy->addFuzzyRule(fuzzyRule9);
  //  
  
  //rule10
  FuzzyRuleAntecedent *rileks_tenang_10 = new FuzzyRuleAntecedent();
  rileks_tenang_10->joinWithAND(rileks, tenang);

  FuzzyRuleAntecedent *c2_chill = new FuzzyRuleAntecedent();
  c2_chill->joinSingle(chill);

  FuzzyRuleAntecedent *rileks_cemas_chill_10 = new FuzzyRuleAntecedent();
  rileks_cemas_chill_10->joinWithAND(rileks_tenang_10, c2_chill);

  FuzzyRuleConsequent *c_10 = new FuzzyRuleConsequent();
  c_10->addOutput(c);

  FuzzyRule *fuzzyRule10 = new FuzzyRule(10, rileks_cemas_chill_10, c_10);
  fuzzy->addFuzzyRule(fuzzyRule10);
  //
  
  //rule11  
  FuzzyRuleAntecedent *rileks_tenang_11 = new FuzzyRuleAntecedent();
  rileks_tenang_11->joinWithAND(rileks, tenang);

  FuzzyRuleAntecedent *c1_worry = new FuzzyRuleAntecedent();
  c1_worry->joinSingle(worry);

  FuzzyRuleAntecedent *rileks_cemas_worry_11 = new FuzzyRuleAntecedent();
  rileks_cemas_worry_11->joinWithAND(rileks_tenang_11, c1_worry);

  FuzzyRuleConsequent *c_11 = new FuzzyRuleConsequent();
  c_11->addOutput(c);

  FuzzyRule *fuzzyRule11 = new FuzzyRule(11, rileks_cemas_worry_11, c_11);
  fuzzy->addFuzzyRule(fuzzyRule11);
  //
  
  //rule12
  FuzzyRuleAntecedent *rileks_tenang_12 = new FuzzyRuleAntecedent();
  rileks_tenang_12->joinWithAND(rileks, tenang);

  FuzzyRuleAntecedent *a1_nervous = new FuzzyRuleAntecedent();
  a1_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *rileks_tenang_nervous_12 = new FuzzyRuleAntecedent();
  rileks_tenang_nervous_12->joinWithAND(rileks_tenang_12, a1_nervous);

  FuzzyRuleConsequent *a_12 = new FuzzyRuleConsequent();
  a_12->addOutput(a);

  FuzzyRule *fuzzyRule12 = new FuzzyRule(12, rileks_tenang_nervous_12, a_12);
  fuzzy->addFuzzyRule(fuzzyRule12);
  //
  
  //rule13
  FuzzyRuleAntecedent *rileks_santai_13 = new FuzzyRuleAntecedent();
  rileks_santai_13->joinWithAND(rileks, santai);

  FuzzyRuleAntecedent *r2_relax = new FuzzyRuleAntecedent();
  r2_relax->joinSingle(relax);

  FuzzyRuleAntecedent *rileks_santai_relax_13 = new FuzzyRuleAntecedent();
  rileks_santai_relax_13->joinWithAND(rileks_santai_13, r2_relax);

  FuzzyRuleConsequent *r_13 = new FuzzyRuleConsequent();
  r_13->addOutput(r);

  FuzzyRule *fuzzyRule13 = new FuzzyRule(13, rileks_santai_relax_13, r_13);
  fuzzy->addFuzzyRule(fuzzyRule13);
  //
  
  //rule14
  FuzzyRuleAntecedent *rileks_santai_14 = new FuzzyRuleAntecedent();
  rileks_santai_14->joinWithAND(rileks, santai);

  FuzzyRuleAntecedent *c3_chill = new FuzzyRuleAntecedent();
  c3_chill->joinSingle(chill);

  FuzzyRuleAntecedent *rileks_santai_chill_14 = new FuzzyRuleAntecedent();
  rileks_santai_chill_14->joinWithAND(rileks_santai_14, c3_chill);

  FuzzyRuleConsequent *c_14 = new FuzzyRuleConsequent();
  c_14->addOutput(c);

  FuzzyRule *fuzzyRule14 = new FuzzyRule(14, rileks_santai_chill_14, c_14);
  fuzzy->addFuzzyRule(fuzzyRule14);
  //
  
  //rule15
  FuzzyRuleAntecedent *rileks_santai_15 = new FuzzyRuleAntecedent();
  rileks_santai_15->joinWithAND(rileks, santai);

  FuzzyRuleAntecedent *c2_worry = new FuzzyRuleAntecedent();
  c2_worry->joinSingle(worry);

  FuzzyRuleAntecedent *rileks_santai_worry_15 = new FuzzyRuleAntecedent();
  rileks_santai_worry_15->joinWithAND(rileks_santai_15, c2_worry);

  FuzzyRuleConsequent *c_15 = new FuzzyRuleConsequent();
  c_15->addOutput(c);

  FuzzyRule *fuzzyRule15 = new FuzzyRule(15, rileks_santai_worry_15, c_15);
  fuzzy->addFuzzyRule(fuzzyRule15);
  //
  
  //rule16
  FuzzyRuleAntecedent *rileks_santai_16 = new FuzzyRuleAntecedent();
  rileks_santai_16->joinWithAND(rileks, santai);

  FuzzyRuleAntecedent *a2_nervous = new FuzzyRuleAntecedent();
  a2_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *rileks_santai_nervous_16 = new FuzzyRuleAntecedent();
  rileks_santai_nervous_16->joinWithAND(rileks_santai_16, a2_nervous);

  FuzzyRuleConsequent *a_16 = new FuzzyRuleConsequent();
  a_16->addOutput(a);

  FuzzyRule *fuzzyRule16 = new FuzzyRule(16, rileks_santai_nervous_16, a_16);
  fuzzy->addFuzzyRule(fuzzyRule16);
  //
  
  //rule17
  FuzzyRuleAntecedent *calm_ganyaman_17 = new FuzzyRuleAntecedent();
  calm_ganyaman_17->joinWithAND(calm, ganyaman);

  FuzzyRuleAntecedent *a2_relax = new FuzzyRuleAntecedent();
  a2_relax->joinSingle(relax);

  FuzzyRuleAntecedent *calm_ganyaman_relax_17 = new FuzzyRuleAntecedent();
  calm_ganyaman_relax_17->joinWithAND(calm_ganyaman_17, a2_relax);

  FuzzyRuleConsequent *a_17 = new FuzzyRuleConsequent();
  a_17->addOutput(a);

  FuzzyRule *fuzzyRule17 = new FuzzyRule(17, calm_ganyaman_relax_17, a_17);
  fuzzy->addFuzzyRule(fuzzyRule17);
  //
  
  //rule18
  FuzzyRuleAntecedent *calm_ganyaman_18 = new FuzzyRuleAntecedent();
  calm_ganyaman_18->joinWithAND(calm, ganyaman);

  FuzzyRuleAntecedent *a2_chill = new FuzzyRuleAntecedent();
  a2_chill->joinSingle(chill);

  FuzzyRuleAntecedent *calm_ganyaman_chill_18 = new FuzzyRuleAntecedent();
  calm_ganyaman_chill_18->joinWithAND(calm_ganyaman_18, a2_chill);

  FuzzyRuleConsequent *a_18 = new FuzzyRuleConsequent();
  a_18->addOutput(a);

  FuzzyRule *fuzzyRule18 = new FuzzyRule(18, calm_ganyaman_chill_18, a_18);
  fuzzy->addFuzzyRule(fuzzyRule18);
  //
  
  //rule19
  FuzzyRuleAntecedent *calm_ganyaman_19 = new FuzzyRuleAntecedent();
  calm_ganyaman_19->joinWithAND(calm, ganyaman);

  FuzzyRuleAntecedent *s2_worry = new FuzzyRuleAntecedent();
  s2_worry->joinSingle(worry);

  FuzzyRuleAntecedent *calm_ganyaman_worry_19 = new FuzzyRuleAntecedent();
  calm_ganyaman_worry_19->joinWithAND(calm_ganyaman_19, s2_worry);

  FuzzyRuleConsequent *s_19 = new FuzzyRuleConsequent();
  s_19->addOutput(s);

  FuzzyRule *fuzzyRule19 = new FuzzyRule(19, calm_ganyaman_worry_19, s_19);
  fuzzy->addFuzzyRule(fuzzyRule19);
  //
  
  //rule20
  FuzzyRuleAntecedent *calm_ganyaman_20 = new FuzzyRuleAntecedent();
  calm_ganyaman_20->joinWithAND(calm, ganyaman);

  FuzzyRuleAntecedent *s3_nervous = new FuzzyRuleAntecedent();
  s3_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *calm_ganyaman_nervous_20 = new FuzzyRuleAntecedent();
  calm_ganyaman_nervous_20->joinWithAND(calm_ganyaman_20, s3_nervous);

  FuzzyRuleConsequent *s_20 = new FuzzyRuleConsequent();
  s_20->addOutput(s);

  FuzzyRule *fuzzyRule20 = new FuzzyRule(20, calm_ganyaman_nervous_20, s_20);
  fuzzy->addFuzzyRule(fuzzyRule20);
  //
  
  //rule21
  FuzzyRuleAntecedent *calm_cemas_21 = new FuzzyRuleAntecedent();
  calm_cemas_21->joinWithAND(calm, cemas);

  FuzzyRuleAntecedent *c2_relax = new FuzzyRuleAntecedent();
  c2_relax->joinSingle(relax);

  FuzzyRuleAntecedent *calm_cemas_relax_21 = new FuzzyRuleAntecedent();
  calm_cemas_relax_21->joinWithAND(calm_cemas_21, c2_relax);

  FuzzyRuleConsequent *c_21 = new FuzzyRuleConsequent();
  c_21->addOutput(c);

  FuzzyRule *fuzzyRule21 = new FuzzyRule(21, calm_cemas_relax_21, c_21);
  fuzzy->addFuzzyRule(fuzzyRule21);
  //
  
  //rule22
  FuzzyRuleAntecedent *calm_cemas_22 = new FuzzyRuleAntecedent();
  calm_cemas_22->joinWithAND(calm, cemas);

  FuzzyRuleAntecedent *c4_chill = new FuzzyRuleAntecedent();
  c4_chill->joinSingle(chill);

  FuzzyRuleAntecedent *calm_cemas_chill_22 = new FuzzyRuleAntecedent();
  calm_cemas_chill_22->joinWithAND(calm_cemas_22, c4_chill);

  FuzzyRuleConsequent *c_22 = new FuzzyRuleConsequent();
  c_22->addOutput(c);

  FuzzyRule *fuzzyRule22 = new FuzzyRule(22, calm_cemas_chill_22, c_22);
  fuzzy->addFuzzyRule(fuzzyRule22);
  //
  
  //rule23
  FuzzyRuleAntecedent *calm_cemas_23 = new FuzzyRuleAntecedent();
  calm_cemas_23->joinWithAND(calm, cemas);

  FuzzyRuleAntecedent *a2_worry = new FuzzyRuleAntecedent();
  a2_worry->joinSingle(worry);

  FuzzyRuleAntecedent *calm_cemas_worry_23 = new FuzzyRuleAntecedent();
  calm_cemas_worry_23->joinWithAND(calm_cemas_23, a2_worry);

  FuzzyRuleConsequent *a_23 = new FuzzyRuleConsequent();
  a_23->addOutput(a);

  FuzzyRule *fuzzyRule23 = new FuzzyRule(23, calm_cemas_worry_23, a_23);
  fuzzy->addFuzzyRule(fuzzyRule23);
  //
  
  //rule24
  FuzzyRuleAntecedent *calm_cemas_24 = new FuzzyRuleAntecedent();
  calm_cemas_24->joinWithAND(calm, cemas);

  FuzzyRuleAntecedent *s4_nervous = new FuzzyRuleAntecedent();
  s4_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *calm_cemas_nervous_24 = new FuzzyRuleAntecedent();
  calm_cemas_nervous_24->joinWithAND(calm_cemas_24, s4_nervous);

  FuzzyRuleConsequent *s_24 = new FuzzyRuleConsequent();
  s_24->addOutput(s);

  FuzzyRule *fuzzyRule24 = new FuzzyRule(24, calm_cemas_nervous_24, s_24);
  fuzzy->addFuzzyRule(fuzzyRule24);
  // 
  
  //rule25
  FuzzyRuleAntecedent *calm_tenang_25 = new FuzzyRuleAntecedent();
  calm_tenang_25->joinWithAND(calm, tenang);

  FuzzyRuleAntecedent *c3_relax = new FuzzyRuleAntecedent();
  c3_relax->joinSingle(relax);

  FuzzyRuleAntecedent *calm_tenang_relax_25 = new FuzzyRuleAntecedent();
  calm_tenang_relax_25->joinWithAND(calm_tenang_25, c3_relax);

  FuzzyRuleConsequent *c_25 = new FuzzyRuleConsequent();
  c_25->addOutput(c);

  FuzzyRule *fuzzyRule25 = new FuzzyRule(25, calm_tenang_relax_25, c_25);
  fuzzy->addFuzzyRule(fuzzyRule25);
  // 
  
  //rule26
  FuzzyRuleAntecedent *calm_tenang_26 = new FuzzyRuleAntecedent();
  calm_tenang_26->joinWithAND(calm, tenang);

  FuzzyRuleAntecedent *c5_chill = new FuzzyRuleAntecedent();
  c5_chill->joinSingle(chill);

  FuzzyRuleAntecedent *calm_tenang_chill_26 = new FuzzyRuleAntecedent();
  calm_tenang_chill_26->joinWithAND(calm_tenang_26, c5_chill);

  FuzzyRuleConsequent *c_26 = new FuzzyRuleConsequent();
  c_26->addOutput(c);

  FuzzyRule *fuzzyRule26 = new FuzzyRule(26, calm_tenang_chill_26, c_26);
  fuzzy->addFuzzyRule(fuzzyRule26);
  // 
  
  //rule27
  FuzzyRuleAntecedent *calm_tenang_27 = new FuzzyRuleAntecedent();
  calm_tenang_27->joinWithAND(calm, tenang);

  FuzzyRuleAntecedent *c3_worry = new FuzzyRuleAntecedent();
  c3_worry->joinSingle(worry);

  FuzzyRuleAntecedent *calm_tenang_worry_27 = new FuzzyRuleAntecedent();
  calm_tenang_worry_27->joinWithAND(calm_tenang_27, c3_worry);

  FuzzyRuleConsequent *c_27 = new FuzzyRuleConsequent();
  c_27->addOutput(c);

  FuzzyRule *fuzzyRule27 = new FuzzyRule(27, calm_tenang_worry_27, c_27);
  fuzzy->addFuzzyRule(fuzzyRule27);
  // 
  
  //rule28
  FuzzyRuleAntecedent *calm_tenang_28 = new FuzzyRuleAntecedent();
  calm_tenang_28->joinWithAND(calm, tenang);

  FuzzyRuleAntecedent *a3_nervous = new FuzzyRuleAntecedent();
  a3_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *calm_tenang_nervous_28 = new FuzzyRuleAntecedent();
  calm_tenang_nervous_28->joinWithAND(calm_tenang_28, a3_nervous);

  FuzzyRuleConsequent *a_28 = new FuzzyRuleConsequent();
  a_28->addOutput(a);

  FuzzyRule *fuzzyRule28 = new FuzzyRule(28, calm_tenang_nervous_28, a_28);
  fuzzy->addFuzzyRule(fuzzyRule28);
  // 

  //rule29
  FuzzyRuleAntecedent *calm_santai_29 = new FuzzyRuleAntecedent();
  calm_santai_29->joinWithAND(calm, santai);

  FuzzyRuleAntecedent *r3_relax = new FuzzyRuleAntecedent();
  r3_relax->joinSingle(relax);

  FuzzyRuleAntecedent *calm_santai_relax_29 = new FuzzyRuleAntecedent();
  calm_santai_relax_29->joinWithAND(calm_santai_29, r3_relax);

  FuzzyRuleConsequent *r_29 = new FuzzyRuleConsequent();
  r_29->addOutput(r);

  FuzzyRule *fuzzyRule29 = new FuzzyRule(29, calm_santai_relax_29, r_29);
  fuzzy->addFuzzyRule(fuzzyRule29);
  // 
  
  //rule30
  FuzzyRuleAntecedent *calm_santai_30 = new FuzzyRuleAntecedent();
  calm_santai_30->joinWithAND(calm, santai);

  FuzzyRuleAntecedent *c6_chill = new FuzzyRuleAntecedent();
  c6_chill->joinSingle(chill);

  FuzzyRuleAntecedent *calm_santai_chill_30 = new FuzzyRuleAntecedent();
  calm_santai_chill_30->joinWithAND(calm_santai_30, c6_chill);

  FuzzyRuleConsequent *c_30 = new FuzzyRuleConsequent();
  c_30->addOutput(c);

  FuzzyRule *fuzzyRule30 = new FuzzyRule(30, calm_santai_chill_30, c_30);
  fuzzy->addFuzzyRule(fuzzyRule30);
  // 
  
  //rule31
  FuzzyRuleAntecedent *calm_santai_31 = new FuzzyRuleAntecedent();
  calm_santai_31->joinWithAND(calm, santai);

  FuzzyRuleAntecedent *c4_worry = new FuzzyRuleAntecedent();
  c4_worry->joinSingle(worry);

  FuzzyRuleAntecedent *calm_santai_worry_31 = new FuzzyRuleAntecedent();
  calm_santai_worry_31->joinWithAND(calm_santai_31, c4_worry);

  FuzzyRuleConsequent *c_31 = new FuzzyRuleConsequent();
  c_31->addOutput(c);

  FuzzyRule *fuzzyRule31 = new FuzzyRule(31, calm_santai_worry_31, c_31);
  fuzzy->addFuzzyRule(fuzzyRule31);
  // 
  
  //rule32
  FuzzyRuleAntecedent *calm_santai_32 = new FuzzyRuleAntecedent();
  calm_santai_32->joinWithAND(calm, santai);

  FuzzyRuleAntecedent *a4_nervous = new FuzzyRuleAntecedent();
  a4_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *calm_santai_nervous_32 = new FuzzyRuleAntecedent();
  calm_santai_nervous_32->joinWithAND(calm_santai_32, a4_nervous);

  FuzzyRuleConsequent *a_32 = new FuzzyRuleConsequent();
  a_32->addOutput(a);

  FuzzyRule *fuzzyRule32 = new FuzzyRule(32, calm_santai_nervous_32, a_32);
  fuzzy->addFuzzyRule(fuzzyRule32);
  // 
  
  //rule33
  FuzzyRuleAntecedent *anxiety_ganyaman_33 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_33->joinWithAND(anxiety, ganyaman);

  FuzzyRuleAntecedent *s1_relax = new FuzzyRuleAntecedent();
  s1_relax->joinSingle(relax);

  FuzzyRuleAntecedent *anxiety_ganyaman_relax_33 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_relax_33->joinWithAND(anxiety_ganyaman_33, s1_relax);

  FuzzyRuleConsequent *s_33 = new FuzzyRuleConsequent();
  s_33->addOutput(s);

  FuzzyRule *fuzzyRule33 = new FuzzyRule(33, anxiety_ganyaman_relax_33, s_33);
  fuzzy->addFuzzyRule(fuzzyRule33);
  // 
  
  //rule34
  FuzzyRuleAntecedent *anxiety_ganyaman_34 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_34->joinWithAND(anxiety, ganyaman);

  FuzzyRuleAntecedent *s1_chill = new FuzzyRuleAntecedent();
  s1_chill->joinSingle(chill);

  FuzzyRuleAntecedent *anxiety_ganyaman_chill_34 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_chill_34->joinWithAND(anxiety_ganyaman_34, s1_chill);

  FuzzyRuleConsequent *s_34 = new FuzzyRuleConsequent();
  s_34->addOutput(s);

  FuzzyRule *fuzzyRule34 = new FuzzyRule(34, anxiety_ganyaman_chill_34, s_34);
  fuzzy->addFuzzyRule(fuzzyRule34);
  // 
  
  //rule35
  FuzzyRuleAntecedent *anxiety_ganyaman_35 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_35->joinWithAND(anxiety, ganyaman);

  FuzzyRuleAntecedent *s3_worry = new FuzzyRuleAntecedent();
  s3_worry->joinSingle(worry);

  FuzzyRuleAntecedent *anxiety_ganyaman_worry_35 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_worry_35->joinWithAND(anxiety_ganyaman_35, s3_worry);

  FuzzyRuleConsequent *s_35 = new FuzzyRuleConsequent();
  s_35->addOutput(s);

  FuzzyRule *fuzzyRule35 = new FuzzyRule(35, anxiety_ganyaman_worry_35, s_35);
  fuzzy->addFuzzyRule(fuzzyRule35);
  // 
  
  //rule36
  FuzzyRuleAntecedent *anxiety_ganyaman_36 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_36->joinWithAND(anxiety, ganyaman);

  FuzzyRuleAntecedent *s5_nervous = new FuzzyRuleAntecedent();
  s5_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *anxiety_ganyaman_nervous_36 = new FuzzyRuleAntecedent();
  anxiety_ganyaman_nervous_36->joinWithAND(anxiety_ganyaman_36, s5_nervous);

  FuzzyRuleConsequent *s_36 = new FuzzyRuleConsequent();
  s_36->addOutput(s);

  FuzzyRule *fuzzyRule36 = new FuzzyRule(36, anxiety_ganyaman_nervous_36, s_36);
  fuzzy->addFuzzyRule(fuzzyRule36);
  // 
  
  //rule37
  FuzzyRuleAntecedent *anxiety_cemas_37 = new FuzzyRuleAntecedent();
  anxiety_cemas_37->joinWithAND(anxiety, cemas);

  FuzzyRuleAntecedent *a3_relax = new FuzzyRuleAntecedent();
  a3_relax->joinSingle(relax);

  FuzzyRuleAntecedent *anxiety_cemas_relax_37 = new FuzzyRuleAntecedent();
  anxiety_cemas_relax_37->joinWithAND(anxiety_cemas_37, a3_relax);

  FuzzyRuleConsequent *a_37 = new FuzzyRuleConsequent();
  a_37->addOutput(a);

  FuzzyRule *fuzzyRule37 = new FuzzyRule(37, anxiety_cemas_relax_37, a_37);
  fuzzy->addFuzzyRule(fuzzyRule37);
  // 
  
  //rule38
  FuzzyRuleAntecedent *anxiety_cemas_38 = new FuzzyRuleAntecedent();
  anxiety_cemas_38->joinWithAND(anxiety, cemas);

  FuzzyRuleAntecedent *a3_chill = new FuzzyRuleAntecedent();
  a3_chill->joinSingle(chill);

  FuzzyRuleAntecedent *anxiety_cemas_chill_38 = new FuzzyRuleAntecedent();
  anxiety_cemas_chill_38->joinWithAND(anxiety_cemas_38, a3_chill);

  FuzzyRuleConsequent *a_38 = new FuzzyRuleConsequent();
  a_38->addOutput(a);

  FuzzyRule *fuzzyRule38 = new FuzzyRule(38, anxiety_cemas_chill_38, a_38);
  fuzzy->addFuzzyRule(fuzzyRule38);
  // 
  
  //rule39
  FuzzyRuleAntecedent *anxiety_cemas_39 = new FuzzyRuleAntecedent();
  anxiety_cemas_39->joinWithAND(anxiety, cemas);

  FuzzyRuleAntecedent *a3_worry = new FuzzyRuleAntecedent();
  a3_worry->joinSingle(worry);

  FuzzyRuleAntecedent *anxiety_cemas_worry_39 = new FuzzyRuleAntecedent();
  anxiety_cemas_worry_39->joinWithAND(anxiety_cemas_39, a3_worry);

  FuzzyRuleConsequent *a_39 = new FuzzyRuleConsequent();
  a_39->addOutput(a);

  FuzzyRule *fuzzyRule39 = new FuzzyRule(39, anxiety_cemas_worry_39, a_39);
  fuzzy->addFuzzyRule(fuzzyRule39);
  // 
  
  //rule40
  FuzzyRuleAntecedent *anxiety_cemas_40 = new FuzzyRuleAntecedent();
  anxiety_cemas_40->joinWithAND(anxiety, cemas);

  FuzzyRuleAntecedent *s6_nervous = new FuzzyRuleAntecedent();
  s6_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *anxiety_cemas_nervous_40 = new FuzzyRuleAntecedent();
  anxiety_cemas_nervous_40->joinWithAND(anxiety_cemas_40, s6_nervous);

  FuzzyRuleConsequent *s_40 = new FuzzyRuleConsequent();
  s_40->addOutput(s);

  FuzzyRule *fuzzyRule40 = new FuzzyRule(40, anxiety_cemas_nervous_40, s_40);
  fuzzy->addFuzzyRule(fuzzyRule40);
  // 
  
  //rule41
  FuzzyRuleAntecedent *anxiety_tenang_41 = new FuzzyRuleAntecedent();
  anxiety_tenang_41->joinWithAND(anxiety, tenang);

  FuzzyRuleAntecedent *c5_relax = new FuzzyRuleAntecedent();
  c5_relax->joinSingle(relax);

  FuzzyRuleAntecedent *anxiety_tenang_relax_41 = new FuzzyRuleAntecedent();
  anxiety_tenang_relax_41->joinWithAND(anxiety_tenang_41, c5_relax);

  FuzzyRuleConsequent *c_41 = new FuzzyRuleConsequent();
  c_41->addOutput(c);

  FuzzyRule *fuzzyRule41 = new FuzzyRule(41, anxiety_tenang_relax_41, c_41);
  fuzzy->addFuzzyRule(fuzzyRule41);
  // 
  
  //rule42
  FuzzyRuleAntecedent *anxiety_tenang_42 = new FuzzyRuleAntecedent();
  anxiety_tenang_42->joinWithAND(anxiety, tenang);

  FuzzyRuleAntecedent *c7_chill = new FuzzyRuleAntecedent();
  c7_chill->joinSingle(chill);

  FuzzyRuleAntecedent *anxiety_tenang_chill_42 = new FuzzyRuleAntecedent();
  anxiety_tenang_chill_42->joinWithAND(anxiety_tenang_42, c7_chill);

  FuzzyRuleConsequent *c_42 = new FuzzyRuleConsequent();
  c_42->addOutput(c);

  FuzzyRule *fuzzyRule42 = new FuzzyRule(42, anxiety_tenang_chill_42, c_42);
  fuzzy->addFuzzyRule(fuzzyRule42);
  // 
  
  //rule43
  FuzzyRuleAntecedent *anxiety_tenang_43 = new FuzzyRuleAntecedent();
  anxiety_tenang_43->joinWithAND(anxiety, tenang);

  FuzzyRuleAntecedent *a4_worry = new FuzzyRuleAntecedent();
  a4_worry->joinSingle(worry);

  FuzzyRuleAntecedent *anxiety_tenang_worry_43 = new FuzzyRuleAntecedent();
  anxiety_tenang_worry_43->joinWithAND(anxiety_tenang_43, a4_worry);

  FuzzyRuleConsequent *a_43 = new FuzzyRuleConsequent();
  a_43->addOutput(a);

  FuzzyRule *fuzzyRule43 = new FuzzyRule(43, anxiety_tenang_worry_43, a_43);
  fuzzy->addFuzzyRule(fuzzyRule43);
  // 
  
  //rule44
  FuzzyRuleAntecedent *anxiety_tenang_44 = new FuzzyRuleAntecedent();
  anxiety_tenang_44->joinWithAND(anxiety, tenang);

  FuzzyRuleAntecedent *s7_nervous = new FuzzyRuleAntecedent();
  s7_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *anxiety_tenang_nervous_44 = new FuzzyRuleAntecedent();
  anxiety_tenang_nervous_44->joinWithAND(anxiety_tenang_44, s7_nervous);

  FuzzyRuleConsequent *s_44 = new FuzzyRuleConsequent();
  s_44->addOutput(s);

  FuzzyRule *fuzzyRule44 = new FuzzyRule(44, anxiety_tenang_nervous_44, s_44);
  fuzzy->addFuzzyRule(fuzzyRule44);
  // 
  
  //rule45
  FuzzyRuleAntecedent *anxiety_santai_45 = new FuzzyRuleAntecedent();
  anxiety_santai_45->joinWithAND(anxiety, santai);

  FuzzyRuleAntecedent *c6_relax = new FuzzyRuleAntecedent();
  c6_relax->joinSingle(relax);

  FuzzyRuleAntecedent *anxiety_santai_relax_45 = new FuzzyRuleAntecedent();
  anxiety_santai_relax_45->joinWithAND(anxiety_santai_45, c6_relax);

  FuzzyRuleConsequent *c_45 = new FuzzyRuleConsequent();
  c_45->addOutput(c);

  FuzzyRule *fuzzyRule45 = new FuzzyRule(45, anxiety_santai_relax_45, c_45);
  fuzzy->addFuzzyRule(fuzzyRule45);
  // 
  
  //rule46
  FuzzyRuleAntecedent *anxiety_santai_46 = new FuzzyRuleAntecedent();
  anxiety_santai_46->joinWithAND(anxiety, santai);

  FuzzyRuleAntecedent *c8_chill = new FuzzyRuleAntecedent();
  c8_chill->joinSingle(chill);

  FuzzyRuleAntecedent *anxiety_santai_chill_46 = new FuzzyRuleAntecedent();
  anxiety_santai_chill_46->joinWithAND(anxiety_santai_46, c8_chill);

  FuzzyRuleConsequent *c_46 = new FuzzyRuleConsequent();
  c_46->addOutput(c);

  FuzzyRule *fuzzyRule46 = new FuzzyRule(46, anxiety_santai_chill_46, c_46);
  fuzzy->addFuzzyRule(fuzzyRule46);
  // 

  //rule47
  FuzzyRuleAntecedent *anxiety_santai_47 = new FuzzyRuleAntecedent();
  anxiety_santai_47->joinWithAND(anxiety, santai);

  FuzzyRuleAntecedent *a5_worry = new FuzzyRuleAntecedent();
  a5_worry->joinSingle(worry);

  FuzzyRuleAntecedent *anxiety_santai_worry_47 = new FuzzyRuleAntecedent();
  anxiety_santai_worry_47->joinWithAND(anxiety_santai_47, a5_worry);

  FuzzyRuleConsequent *a_47 = new FuzzyRuleConsequent();
  a_47->addOutput(a);

  FuzzyRule *fuzzyRule47 = new FuzzyRule(47, anxiety_santai_worry_47, a_47);
  fuzzy->addFuzzyRule(fuzzyRule47);
  // 
  
  //rule48
  FuzzyRuleAntecedent *anxiety_santai_48 = new FuzzyRuleAntecedent();
  anxiety_santai_48->joinWithAND(anxiety, santai);

  FuzzyRuleAntecedent *a5_nervous = new FuzzyRuleAntecedent();
  a5_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *anxiety_santai_nervous_48 = new FuzzyRuleAntecedent();
  anxiety_santai_nervous_48->joinWithAND(anxiety_santai_48, a5_nervous);

  FuzzyRuleConsequent *a_48 = new FuzzyRuleConsequent();
  a_48->addOutput(a);

  FuzzyRule *fuzzyRule48 = new FuzzyRule(48, anxiety_santai_nervous_48, a_48);
  fuzzy->addFuzzyRule(fuzzyRule48);
  // 
  
  //rule49
  FuzzyRuleAntecedent *stress_ganyaman_49 = new FuzzyRuleAntecedent();
  stress_ganyaman_49->joinWithAND(stress, ganyaman);

  FuzzyRuleAntecedent *a4_relax = new FuzzyRuleAntecedent();
  a4_relax->joinSingle(relax);

  FuzzyRuleAntecedent *stress_ganyaman_relax_49 = new FuzzyRuleAntecedent();
  stress_ganyaman_relax_49->joinWithAND(stress_ganyaman_49, a4_relax);

  FuzzyRuleConsequent *a_49 = new FuzzyRuleConsequent();
  a_49->addOutput(a);

  FuzzyRule *fuzzyRule49 = new FuzzyRule(49, stress_ganyaman_relax_49, a_49);
  fuzzy->addFuzzyRule(fuzzyRule49);
  // 
  
  //rule50
  FuzzyRuleAntecedent *stress_ganyaman_50 = new FuzzyRuleAntecedent();
  stress_ganyaman_50->joinWithAND(stress, ganyaman);

  FuzzyRuleAntecedent *a4_chill = new FuzzyRuleAntecedent();
  a4_chill->joinSingle(chill);

  FuzzyRuleAntecedent *stress_ganyaman_chill_50 = new FuzzyRuleAntecedent();
  stress_ganyaman_chill_50->joinWithAND(stress_ganyaman_50, a4_chill);

  FuzzyRuleConsequent *a_50 = new FuzzyRuleConsequent();
  a_50->addOutput(a);

  FuzzyRule *fuzzyRule50 = new FuzzyRule(50, stress_ganyaman_chill_50, a_50);
  fuzzy->addFuzzyRule(fuzzyRule50);
  // 
  
  //rule51
  FuzzyRuleAntecedent *stress_ganyaman_51 = new FuzzyRuleAntecedent();
  stress_ganyaman_51->joinWithAND(stress, ganyaman);

  FuzzyRuleAntecedent *s4_worry = new FuzzyRuleAntecedent();
  s4_worry->joinSingle(worry);

  FuzzyRuleAntecedent *stress_ganyaman_worry_51 = new FuzzyRuleAntecedent();
  stress_ganyaman_worry_51->joinWithAND(stress_ganyaman_51, s4_worry);

  FuzzyRuleConsequent *s_51 = new FuzzyRuleConsequent();
  s_51->addOutput(s);

  FuzzyRule *fuzzyRule51 = new FuzzyRule(51, stress_ganyaman_worry_51, s_51);
  fuzzy->addFuzzyRule(fuzzyRule51);
  // 
  
  //rule52
  FuzzyRuleAntecedent *stress_ganyaman_52 = new FuzzyRuleAntecedent();
  stress_ganyaman_52->joinWithAND(stress, ganyaman);

  FuzzyRuleAntecedent *s8_nervous = new FuzzyRuleAntecedent();
  s8_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *stress_ganyaman_nervous_52 = new FuzzyRuleAntecedent();
  stress_ganyaman_nervous_52->joinWithAND(stress_ganyaman_52, s8_nervous);

  FuzzyRuleConsequent *s_52 = new FuzzyRuleConsequent();
  s_52->addOutput(s);

  FuzzyRule *fuzzyRule52 = new FuzzyRule(52, stress_ganyaman_nervous_52, s_52);
  fuzzy->addFuzzyRule(fuzzyRule52);
  //
  
  //rule53
  FuzzyRuleAntecedent *stress_cemas_53 = new FuzzyRuleAntecedent();
  stress_cemas_53->joinWithAND(stress, cemas);

  FuzzyRuleAntecedent *s2_relax = new FuzzyRuleAntecedent();
  s2_relax->joinSingle(relax);

  FuzzyRuleAntecedent *stress_cemas_relax_53 = new FuzzyRuleAntecedent();
  stress_cemas_relax_53->joinWithAND(stress_cemas_53, s2_relax);

  FuzzyRuleConsequent *s_53 = new FuzzyRuleConsequent();
  s_53->addOutput(s);

  FuzzyRule *fuzzyRule53 = new FuzzyRule(53, stress_cemas_relax_53, s_53);
  fuzzy->addFuzzyRule(fuzzyRule53);
  //
  
  //rule54
  FuzzyRuleAntecedent *stress_cemas_54 = new FuzzyRuleAntecedent();
  stress_cemas_54->joinWithAND(stress, cemas);

  FuzzyRuleAntecedent *s2_chill = new FuzzyRuleAntecedent();
  s2_chill->joinSingle(chill);

  FuzzyRuleAntecedent *stress_cemas_chill_54 = new FuzzyRuleAntecedent();
  stress_cemas_chill_54->joinWithAND(stress_cemas_54, s2_chill);

  FuzzyRuleConsequent *s_54 = new FuzzyRuleConsequent();
  s_54->addOutput(s);

  FuzzyRule *fuzzyRule54 = new FuzzyRule(54, stress_cemas_chill_54, s_54);
  fuzzy->addFuzzyRule(fuzzyRule54);
  //
  
  //rule55
  FuzzyRuleAntecedent *stress_cemas_55 = new FuzzyRuleAntecedent();
  stress_cemas_55->joinWithAND(stress, cemas);

  FuzzyRuleAntecedent *s5_worry = new FuzzyRuleAntecedent();
  s5_worry->joinSingle(worry);

  FuzzyRuleAntecedent *stress_cemas_worry_55 = new FuzzyRuleAntecedent();
  stress_cemas_worry_55->joinWithAND(stress_cemas_55, s5_worry);

  FuzzyRuleConsequent *s_55 = new FuzzyRuleConsequent();
  s_55->addOutput(s);

  FuzzyRule *fuzzyRule55 = new FuzzyRule(55, stress_cemas_worry_55, s_55);
  fuzzy->addFuzzyRule(fuzzyRule55);
  //
  
  //rule56
  FuzzyRuleAntecedent *stress_cemas_56 = new FuzzyRuleAntecedent();
  stress_cemas_56->joinWithAND(stress, cemas);

  FuzzyRuleAntecedent *s9_nervous = new FuzzyRuleAntecedent();
  s9_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *stress_cemas_nervous_56 = new FuzzyRuleAntecedent();
  stress_cemas_nervous_56->joinWithAND(stress_cemas_56, s9_nervous);

  FuzzyRuleConsequent *s_56 = new FuzzyRuleConsequent();
  s_56->addOutput(s);

  FuzzyRule *fuzzyRule56 = new FuzzyRule(56, stress_cemas_nervous_56, s_56);
  fuzzy->addFuzzyRule(fuzzyRule56);
  //
  
  //rule57
  FuzzyRuleAntecedent *stress_tenang_57 = new FuzzyRuleAntecedent();
  stress_tenang_57->joinWithAND(stress, tenang);

  FuzzyRuleAntecedent *a5_relax = new FuzzyRuleAntecedent();
  a5_relax->joinSingle(relax);

  FuzzyRuleAntecedent *stress_tenang_relax_57 = new FuzzyRuleAntecedent();
  stress_tenang_relax_57->joinWithAND(stress_tenang_57, a5_relax);

  FuzzyRuleConsequent *a_57 = new FuzzyRuleConsequent();
  a_57->addOutput(a);

  FuzzyRule *fuzzyRule57 = new FuzzyRule(57, stress_tenang_relax_57, a_57);
  fuzzy->addFuzzyRule(fuzzyRule57);
  //
  
  //rule58
  FuzzyRuleAntecedent *stress_tenang_58 = new FuzzyRuleAntecedent();
  stress_tenang_58->joinWithAND(stress, tenang);

  FuzzyRuleAntecedent *a5_chill = new FuzzyRuleAntecedent();
  a5_chill->joinSingle(chill);

  FuzzyRuleAntecedent *stress_tenang_chill_58 = new FuzzyRuleAntecedent();
  stress_tenang_chill_58->joinWithAND(stress_tenang_58, a5_chill);

  FuzzyRuleConsequent *a_58 = new FuzzyRuleConsequent();
  a_58->addOutput(a);

  FuzzyRule *fuzzyRule58 = new FuzzyRule(58, stress_tenang_chill_58, a_58);
  fuzzy->addFuzzyRule(fuzzyRule58);
  //
  
  //rule59
  FuzzyRuleAntecedent *stress_tenang_59 = new FuzzyRuleAntecedent();
  stress_tenang_59->joinWithAND(stress, tenang);

  FuzzyRuleAntecedent *a6_worry = new FuzzyRuleAntecedent();
  a6_worry->joinSingle(worry);

  FuzzyRuleAntecedent *stress_tenang_worry_59 = new FuzzyRuleAntecedent();
  stress_tenang_worry_59->joinWithAND(stress_tenang_59, a6_worry);

  FuzzyRuleConsequent *a_59 = new FuzzyRuleConsequent();
  a_59->addOutput(a);

  FuzzyRule *fuzzyRule59 = new FuzzyRule(59, stress_tenang_worry_59, a_59);
  fuzzy->addFuzzyRule(fuzzyRule59);
  //
    
  //rule60
  FuzzyRuleAntecedent *stress_tenang_60 = new FuzzyRuleAntecedent();
  stress_tenang_60->joinWithAND(stress, tenang);

  FuzzyRuleAntecedent *s10_nervous = new FuzzyRuleAntecedent();
  s10_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *stress_tenang_nervous_60 = new FuzzyRuleAntecedent();
  stress_tenang_nervous_60->joinWithAND(stress_tenang_60, s10_nervous);

  FuzzyRuleConsequent *s_60 = new FuzzyRuleConsequent();
  s_60->addOutput(s);

  FuzzyRule *fuzzyRule60 = new FuzzyRule(60, stress_tenang_nervous_60, s_60);
  fuzzy->addFuzzyRule(fuzzyRule60);
  //
  
  //rule61
  
  FuzzyRuleAntecedent *stress_santai_61 = new FuzzyRuleAntecedent();
  stress_santai_61->joinWithAND(stress, santai);

  FuzzyRuleAntecedent *a6_relax = new FuzzyRuleAntecedent();
  a6_relax->joinSingle(relax);

  FuzzyRuleAntecedent *stress_santai_relax_61 = new FuzzyRuleAntecedent();
  stress_santai_relax_61->joinWithAND(stress_santai_61, a6_relax);

  FuzzyRuleConsequent *a_61 = new FuzzyRuleConsequent();
  a_61->addOutput(a);

  FuzzyRule *fuzzyRule61 = new FuzzyRule(61, stress_santai_relax_61, a_61);
  fuzzy->addFuzzyRule(fuzzyRule61);
  //
  
  //rule62
  FuzzyRuleAntecedent *stress_santai_62 = new FuzzyRuleAntecedent();
  stress_santai_62->joinWithAND(stress, santai);

  FuzzyRuleAntecedent *a6_chill = new FuzzyRuleAntecedent();
  a6_chill->joinSingle(chill);

  FuzzyRuleAntecedent *stress_santai_chill_62= new FuzzyRuleAntecedent();
  stress_santai_chill_62->joinWithAND(stress_santai_62, a6_chill);

  FuzzyRuleConsequent *a_62 = new FuzzyRuleConsequent();
  a_62->addOutput(a);

  FuzzyRule *fuzzyRule62 = new FuzzyRule(62, stress_santai_chill_62, a_62);
  fuzzy->addFuzzyRule(fuzzyRule62);
  //
  
  //rule63
  FuzzyRuleAntecedent *stress_santai_63 = new FuzzyRuleAntecedent();
  stress_santai_63->joinWithAND(stress, santai);

  FuzzyRuleAntecedent *a7_worry = new FuzzyRuleAntecedent();
  a7_worry->joinSingle(worry);

  FuzzyRuleAntecedent *stress_santai_worry_63 = new FuzzyRuleAntecedent();
  stress_santai_worry_63->joinWithAND(stress_santai_63, a7_worry);

  FuzzyRuleConsequent *a_63 = new FuzzyRuleConsequent();
  a_63->addOutput(a);

  FuzzyRule *fuzzyRule63 = new FuzzyRule(63, stress_santai_worry_63, a_63);
  fuzzy->addFuzzyRule(fuzzyRule63);
  //
  
  //rule64
  FuzzyRuleAntecedent *stress_santai_64 = new FuzzyRuleAntecedent();
  stress_santai_64->joinWithAND(stress, santai);

  FuzzyRuleAntecedent *s11_nervous = new FuzzyRuleAntecedent();
  s11_nervous->joinSingle(nervous);

  FuzzyRuleAntecedent *stress_santai_nervous_64 = new FuzzyRuleAntecedent();
  stress_santai_nervous_64->joinWithAND(stress_santai_64, s11_nervous);

  FuzzyRuleConsequent *s_64 = new FuzzyRuleConsequent();
  s_64->addOutput(s);

  FuzzyRule *fuzzyRule64 = new FuzzyRule(64, stress_santai_nervous_64, s_64);
  fuzzy->addFuzzyRule(fuzzyRule64);

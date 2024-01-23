/*
__        _______    ____    _    ____  _____
\ \      / / ____|  / ___|  / \  |  _ \| ____|
 \ \ /\ / /|  _|   | |     / _ \ | |_) |  _|
  \ V  V / | |___  | |___ / ___ \|  _ <| |___
   \_/\_/  |_____|  \____/_/   \_\_| \_\_____|
   THE VIRTUAL HEALTH ASSISTANT:-
   * */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct person{
    char name[50],B[50];
    int age;
    float weight,height;
    char Gender;
}people[50];
int n=0;
float calculatebmr(int age, int weight, int height, char gender)
{
// Calculate BMR (Basal Metabolic Rate) based on Harris-Benedict equation
float bmr;
if (gender == 'M' || gender == 'm')
{
bmr = 10 * weight + 6 * height - 5 * age + 5;
}
else if (gender == 'F' || gender == 'f')
{
bmr = 10 * weight + 6 * height - 5 * age - 161;
}
else
{
printf("Invalid gender input. Please enter 'M' for male or 'F' for female.\n");
return 0;
}
return bmr;
}
//Function to calculate daily calorie requirement base on activity level
float calculateDailyCalories(float bmr , int activityLevel)
{
float dailyCalories;
switch (activityLevel)
{
case 1://Sedentary
dailyCalories = bmr * 1.2;
break;
case 2://Lightly Active
dailyCalories = bmr * 1.375;
break;
case 3://Moderately Active
dailyCalories = bmr * 1.55;
break;
case 4://Very Active
dailyCalories = bmr * 1.725;
break;
case 5://Extremely Active
dailyCalories = bmr * 1.9;
break;
default:
printf("Invalid activity level input.\n");
printf("Please enter a number between 1 and 5.\n");
return 0;
}
return dailyCalories;
}
// Function to suggest a basic diet chart
void suggestDietChart(int dailyCalories)
{
// Simple diet suggestions based on total calories
if (dailyCalories < 1200)
{
printf("\033[44m Suggested Diet:\033[0m\n");
printf("\033[1;34m Your daily calorie requirement is very low.\033[0m\n");
printf("\033[1;34m Please consult a doctor or nutritionist before making any changes to your diet.\033[0m\n");
}
else if (dailyCalories < 1500)
{
printf("\033[44mSuggested Diet:\033[0m\n");
printf("\033[1;34mAim for a low-calorie diet of around 1200-1500 calories per day.\033[0m\n");
printf("\033[1;34mFocus on nutrient-dense foods like fruits, vegetables, whole grains, and lean protein.\033[0m\n");
}
else if (dailyCalories < 1800)
{
printf("\033[44mSuggested Diet:\033[0m\n");
printf("\033[1;34mAim for a moderately low calorie diet of around 1500-1800 calories per day.\033[0m\n");
printf("\033[1;34mInclude a variety of nutrient-rich foods and moderate portions of healthy fats.\033[0m\n");
}
else if (dailyCalories < 2200)
{
printf("\033[44mSuggested Diet:\033[0m\n");
printf("\033[1;34mAim for a moderate-calorie diet of around 2200-2500 calories per day.\033[0m\n");
printf("\033[1;34mIncrease your intake of nutrient-dense foods and consider adding healthy snacks.\033[0m\n");
}
else if (dailyCalories < 2500)
{
printf("\033[44mSuggested Diet:\033[0m\n");
printf("\033[1;34mAim for a moderately high-calorie diet of around 2200-2500 calories per day.\033[0m\n");
printf("\033[1;34mIncrease your intake of nutrient-dense foods and consider adding healthy snacks.\033[0m\n");
}
else
{
printf("\033[44mSuggested Diet:\033[0m\n");
printf("\033[1;34mYour daily calorie requirement is high.\033[0m\n");
printf("\033[1;34mPlease consult a doctor or nutritionist to determine the appropriate calorie intake and diet plan.\033[0m\n");
}
}
// Function to identify the compatible Blood Groups
void compatibleBloodgroups(char *bloodgroup)
{
printf("\033[1;33mCompatible blood groups for %s : \033[0m" ,bloodgroup);
if(strcmp(bloodgroup, "A") == 0)
{
printf("\033[1;33mA , AB , O\033[0m\n");
}
else if(strcmp(bloodgroup, "B") == 0)
{
printf("\033[1;33mB , AB , O\033[0m\n");
}
else if(strcmp(bloodgroup, "AB") == 0)
{
printf("\033[1;33mA , B , AB , O\033[0m\n");
}
else if(strcmp(bloodgroup, "O") == 0)
{
printf("\033[1;33mO\033[0m\n");
}
else
{
printf("\033[1;33mInvalid blood group\033[0m\n");
}
}
void DEV()
{
printf("\033[4m**************************************************************************************************************************\033[0m\n");
printf("\033[1mWelcome to the next section\033[0m\n");
printf("\033[3mIn this section we will provide you the approx Calories you burn in a day.\033[0m\n");
printf("\033[3mWe will also sugeest a diet accordingly.\033[0m\n");
// Get user input
int age=people[n].age, weight=people[n].weight, height=people[n].height, activityLevel;
char gender=people[n].Gender;
printf("\033[1;32mEnter your activity level : \033[0m");
printf("(1- Sedentary, 2- Lightly active, 3- Moderately active, 4- Very active, 5- Extremely active): ");
scanf("%d", &activityLevel);
// Calculate total calories
int totalCalories = calculatebmr(age, weight, height, gender);
// Display total calories and suggest a diet chart
printf("\n\033[1;33mTotal Calories: %d\033[0m\n", totalCalories);
//Suggesting a diet by evaluating total calorie intake
printf("\33[4m**************************************************************************************************************************\33[0m\n");
suggestDietChart(totalCalories);
printf("\33[4m**************************************************************************************************************************\33[0m\n");
printf("\033[45mSURPRISING FACT ON CALORIES\033[0m\n");
printf("\033[1;35mProties calories help weight loss.\033[0m\n");
printf("\033[1;35mIf we are getting 25-30 percent of calories from protien,\033[0m");
printf("\033[1;35mthat is where we are going to see a pretty big difference in our body composition\033[0m\n");
printf("\033[1;35m Protiens can provide the following :\033[0m\n");
printf("\033[1;35m1.) Curbing our desire for more food\033[0m\n");
printf("\033[1;35m2.) Increasing muscle mass\033[0m\n");
printf("\033[1;35m3.) Helping with our metabolic rates\033[0m\n");
printf("\33[4m**************************************************************************************************************************\33[0m\n");
getch();
system("cls");
printf("\033[1mWe welcome you again to the next amazing section\033[0m\n");
printf("\033[3mThis part of our WE HEALTH CARE program will help you to identify the blood groups that can provide you the blood when in need\033[0m\n");
// Blood group entered by the user
char userBloodgroup[3];
compatibleBloodgroups(&people[n].B);
printf("\33[4m**************************************************************************************************************************\33[0m\n");
printf("\033[46mSURPRISING FACT ON BLOOD GROUPS\033[0m\n");
printf("\033[1;36m1.) Just 1 donation can save up to 3 lives\033[0m.\n");
printf("\033[1;36m2.) The average red blood cell transfusion is 3 pints.\033[0m\n");
printf("\033[1;36m3.) More than 38,000 blood donations are needed every day.\033[0m\n");
printf("\033[1;36mDONATE BLOOD RESPONSIBLY, NOT ON ROADS BUT AT BLOOD DONATION CAMPS.\033[0m\n");
printf("\033[1;36mALWAYS REMEMBER : THE GIFT OF BLOOD IS THE GIFT OF LIFE.\033[0m\n");
printf("\33[4m**************************************************************************************************************************\33[0m\n");
}

 void skin(){int s;

    system("COLOR 01");
printf("\033[1;35mWELCOME TO OUR SKINCARE DEPARTMENT\nDO YOU KNOW SKIN IS THE LARGEST ORGAN OF HUMAN BODY BUT SADLY IT IS NOT GIVEN ITS DUE CARE ?\033[0m\n");
printf("\033[1;32m------------------------------------------------------------------------------------------------------------------------\033[0m\n");
printf(" \033[1;31m  \n\n\n\t\t\tENTER 1 IF YOUR SKIN TYPE IS OILY  \033[0m\n ");
printf(" \033[1;31m           \t\tENTER 2 IF YOUR SKIN TYPE IS DRY  \033[0m\n ");
printf(" \033[1;31m            \t\tENTER 3 IF YOUR SKIN TYPE IS COMBINATION  \033[0m\n ");
printf(" \033[1;31m            \t\tENTER 4 IF YOUR SKIN TYPE IS SENSITIVE \033[0m\n ");
scanf("%d",&s);
if(s==1)
{
    int c;
   // system("COLOR 79");
    printf(" \033[1;32m THIS IS HOW YOU CAN TAKE CARE OF YOUR OILY SKIN: \033[0m\n ");
    printf(" \033[1;31m  DO wash your face every morning, evening, and after exercise .\033[0m\n ");
    printf(" \033[1;31m DO use a gentle, foaming face wash \033[0m\n ");
    printf(" \033[1;31m DO choose skin care products that are labeled �oil free� and �non comedogenic.� \033[0m\n ");
    printf(" \033[1;31m DO NOT use oil-based or alcohol-based cleansers \033[0m\n ");
    printf("                     \nTHEY SAY PERFECTION IS A MYTH  \n    ");
    printf("        HERE'S HOW YOU CAN OVERCOME YOUR SKIN IMPERFECTIONS: \n ");
    printf(" PRESS 1 FOR FINDNG WAYS TO CURE HORMONAL ACNE OR PIMPLES \n ");
    printf(" PRESS 2 FOR FINDNG WAYS TO CURE MELASMA\n");
    printf(" PRESS 3 FOR FINDNG WAYS TO CURE WRINKLES AND BLEMISHES \n");
    printf(" PRESS 4 FOR FINDNG WAYS TO CURE SIGNS OF PREMATURE AGEING \n ");
    scanf("%d",&c);
   if(c==1)
 {
    system("COLOR C0");

    printf("Wash your skin: Wash your face twice a day with gentle cleansers, exfoliants, and astringents.\n ");
    printf("Use oil-free products: Use oil-free and non-comedogenic skincare and makeup products.\n");
    printf("Avoid stripping your skin: Do not strip your skin of its natural moisture.\n");
    printf("Use an acne treatment: Use an acne treatment recommended by your dermatologist.\n");
    printf(" Protect your skin from the sun: Protect your skin from the sun.\n ");
    printf(" Avoid touching your face: ");

    char a[10];
    printf(" \033[1;31 SALICYLIC ACID and NIACINAMIDE are two active ingredients in face serum to tackle acne   \033[0m\n ");
    printf(" ENTER E IF YOU HAVE PRIOR EXPERIENCE OF USING FACE SERUMS or ENTER N IF YOU ARE A NEWBIE \n");
    scanf("%s",a);
     if(a[0]=='E')
     {
          printf("15 to 20 % concentration recommended for salicylic acid and niacinamide  \n ");
     }
    else if(a[0]=='N')
     {
          printf("5 to 10% concentration recommended for salicylic acid and niacinamide .");
     }
     else
        {
            printf(" \033[1;31m INVALID INPUT\nTRY AGAIN \033[0m\n ");
     }
     printf("\nYour medical provider can give guidance on what is best for your situation. ");
    printf(" This information does not constitute medical advice or diagnosis. ");
}
else if(c==2)
{
    system("COLOR 60");
char a[1];
   printf("Sun protection can help fade melasma and prevent it from returning \n ");
   printf("Hydroquinone: This is a common treatment for melasma.\n ");
   printf("Tretinoin and a mild corticosteroid: This combination contains a retinoid and an anti-inflammatory, which can even out skin tone\n ");

   printf("ENTER E IF YOU HAVE PRIOR EXPERIENCE OF USING the aforestated products");
     printf("  ENTER N IF YOU ARE A NEWBIE ");
     scanf("%s",a);
     if(a[0]=='E')
     {
         system("COLOR E1");
          printf("0.05 to 1.00% concentration recommended for Hydroquinone  ");
     }
    else if(a[0]=='N')
     {
          printf("0.025% concentration recommended for Tretinoin or Hydroquinon");
     }
     else
        {
            printf(" INVALID INPUT\nTRY AGAIN  ");
     }

printf(" NOTE: Your medical provider can give guidance on what is best for your situation.\n ");
printf(" This information does not constitute medical advice or diagnosis.\n ");
}
else if(c==3)
{
    system("COLOR E9");
    printf(" Wash your face: Wash your face twice a day, and again after sweating. \n ");
    printf(" Use gentle products: Avoid hot water, and use gentle cleansing devices. \n ");
    printf(" Avoid touching your face: Popping pimples can trap oil, sebum, and bacteria. \n ");
    printf(" Use oil-free products: Use oil-free and non-comedogenic skincare and makeup products.\n ");
    printf(" Use salicylic acid: Salicylic acid can break down dead skin cells, penetrate pores, and clear out dirt and debris. \n ");
    printf(" \033[1;31 Use retinol: Retinol can help regulate sebum production in oily skin, reducing the likelihood of clogged pores. \n");
    printf(" Use acne treatments: Use an acne treatment recommended by your dermatologist.\n ");
     printf("\n Your medical provider can give guidance on what is best for your situation. \n ");
    printf(" This information does not constitute medical advice or diagnosis.  \n ");
}
else if(c==4)
{
     printf(" There are several lifestyle habits that can help slow down premature aging:\n \033[0m\n ");
      printf(" Eat a healthy, well-balanced diet: Avoid eating too much sugar or refined carbohydrates \033[0m\n ");
       printf("  Protect your skin from the sun: Wear sunscreen with at least SPF 30 every day\033[0m\n ");
        printf(" Exercise most days of the week: Regular physical activity improves circulation and boosts your immune system \033[0m\n ");
         printf(" Sleep well: Maintaining optimal sex hormone levels\033[0m\n ");
          printf(" Drink less alcohol: Alcohol causes premature aging of your skin  \033[0m\n ");
           printf(" Stay hydrated \033[0m\n ");
    printf(" Your medical provider can give guidance on what is best for your situation.  \033[0m\n ");
    printf(" This information does not constitute medical advice or diagnosis.  \033[0m\n ");
}
else
{
  printf(" \033[1;31 INVALID ENTRY \n TRY AGAIN \033[0m\n ");
}
}
else if(s==2)
{
    system("COLOR 09");
    printf(" \033[1;32m THIS IS HOW YOU CAN TAKE CARE OF YOUR DRY SKIN: \033[0m\n ");
    printf(" \033[1;31m  Apply moisturizer immediately after washing \033[0m\n ");
    printf(" \033[1;31m  Stop baths and showers from worsening dry skin.\033[0m\n ");
    printf(" \033[1;31m Use an ointment or cream rather than a lotion. \033[0m\n ");
    printf(" \033[1;31m Ointments and creams are more effective and less irritating than lotions.  \033[0m\n ");
    printf(" \033[1;31m  Look for a cream or ointment that contains one or more of the following ingredients:\033[0m\n ");
    printf(" \033[1;31m \nLactic acid\nLanolin\nMineral oil\nPetrolatum\nShea butter \033[0m\n ");
    printf(" \033[1;31m Alcohol (except for hand sanitizer)\nAlpha-hydroxy acid (AHA) \nRetinoids \033[0m\n ");
printf("                     \nTHEY SAY PERFECTION IS A MYTH  \n    ");
    printf("        HERE'S HOW YOU CAN OVERCOME YOUR SKIN IMPERFECTIONS: \n ");
    printf(" PRESS 1 FOR FINDNG WAYS TO CURE HORMONAL ACNE OR PIMPLES \n ");
    printf(" PRESS 2 FOR FINDNG WAYS TO CURE MELASMA\n");
    printf(" PRESS 3 FOR FINDNG WAYS TO CURE WRINKLES AND BLEMISHES \n");
    printf(" PRESS 4 FOR FINDNG WAYS TO CURE SIGNS OF PREMATURE AGEING \n ");
    int c;
    scanf("%d",&c);
   if(c==1)
   {

   printf(" Wash your face with a gentle acne cleanser in the morning, evening, and after exercising. \n");
   printf(" Avoid over-cleansing or over-exfoliating your skin. \n");
   printf(" This can disrupt the skin�s protective barrier and potentially worsen acne and dryness.  \n");
   printf(" Don�t use harsh astringents or alcohol-based toners, which can strip the skin of its natural moisture. \n");
   printf(" This means that the product won�t clog your pores or contribute to acne breakouts.\n");
   char a[10];
    printf(" \033[1;31 SALICYLIC ACID and NIACINAMIDE are two active ingredients in face serum to tackle acne   \033[0m\n ");
    printf(" ENTER E IF YOU HAVE PRIOR EXPERIENCE OF USING FACE SERUMS or ENTER N IF YOU ARE A NEWBIE \n");
    scanf("%s",a);
     if(a[0]=='E')
     {
          printf("15 to 20 % concentration recommended for salicylic acid and niacinamide  \n ");
     }
    else if(a[0]=='N')
     {
          printf("5 to 10% concentration recommended for salicylic acid and niacinamide .");
     }
     else
        {
            printf(" \033[1;31m INVALID INPUT\nTRY AGAIN \033[0m\n ");
     }
     printf("\nYour medical provider can give guidance on what is best for your situation. ");
    printf(" This information does not constitute medical advice or diagnosis. ");

   }
   else if(c==2)
   {
    system("COLOR 60");
char a[1];
   printf("Sun protection can help fade melasma and prevent it from returning \n ");
   printf("Hydroquinone: This is a common treatment for melasma.\n ");
   printf("Tretinoin and a mild corticosteroid: This combination contains a retinoid and an anti-inflammatory, which can even out skin tone\n ");

   printf("ENTER E IF YOU HAVE PRIOR EXPERIENCE OF USING the aforestated products");
     printf("  ENTER N IF YOU ARE A NEWBIE ");
     scanf("%s",a);
     if(a[0]=='E')
     {
         system("COLOR E1");
          printf("0.05 to 1.00% concentration recommended for Hydroquinone  ");
     }
    else if(a[0]=='N')
     {
          printf("0.025% concentration recommended for Tretinoin or Hydroquinon");
     }
     else
        {
            printf(" INVALID INPUT\nTRY AGAIN  ");
     }
   }

       else if(c==3)
{
    system("COLOR E9");
    printf(" Wash your face: Wash your face twice a day, and again after sweating. \n ");
    printf(" Use gentle products: Avoid hot water, and use gentle cleansing devices. \n ");
    printf(" Avoid touching your face: Popping pimples can trap oil, sebum, and bacteria. \n ");
    printf(" Use oil-free products: Use oil-free and non-comedogenic skincare and makeup products.\n ");
    printf(" Use salicylic acid: Salicylic acid can break down dead skin cells, penetrate pores, and clear out dirt and debris. \n ");
    printf(" \033[1;31 Use retinol: Retinol can help regulate sebum production in oily skin, reducing the likelihood of clogged pores. \n");
    printf(" Use acne treatments: Use an acne treatment recommended by your dermatologist.\n ");
     printf("\n Your medical provider can give guidance on what is best for your situation. \n ");

}
else if(c==4)
{
     printf(" There are several lifestyle habits that can help slow down premature aging:\n \033[0m\n ");
      printf(" Eat a healthy, well-balanced diet: Avoid eating too much sugar or refined carbohydrates \033[0m\n ");
       printf("  Protect your skin from the sun: Wear sunscreen with at least SPF 30 every day\033[0m\n ");
        printf(" Exercise most days of the week: Regular physical activity improves circulation and boosts your immune system \033[0m\n ");
         printf(" Sleep well: Maintaining optimal sex hormone levels\033[0m\n ");
          printf(" Drink less alcohol: Alcohol causes premature aging of your skin  \033[0m\n ");
           printf(" Stay hydrated \033[0m\n ");
    printf(" Your medical provider can give guidance on what is best for your situation.  \033[0m\n ");
    printf(" This information does not constitute medical advice or diagnosis.  \033[0m\n ");
}
else
{
  printf(" \033[1;31 INVALID ENTRY \n TRY AGAIN \033[0m\n ");
   }


}
else if(s==3)
{
    system("COLOR B0");
    printf(" Step-by-Step Routine for Combination Skin\n");
    printf(" Cleanse (Morning & Night)\n");
    printf(" Tone (Morning & Night)\n ");
    printf(" Exfoliate (2-3X Per Week) \n");
    printf(" Sunscreen (Morning) \n");
    printf(" Use a Mask (Weekly) \n ");
    printf(" Make Your Routine a Habit.\n ");

    printf("                     \nTHEY SAY PERFECTION IS A MYTH  \n    ");
    printf("        HERE'S HOW YOU CAN OVERCOME YOUR SKIN IMPERFECTIONS: \n ");
    printf(" PRESS 1 FOR FINDNG WAYS TO CURE HORMONAL ACNE OR PIMPLES \n ");
    printf(" PRESS 2 FOR FINDNG WAYS TO CURE MELASMA\n");
    printf(" PRESS 3 FOR FINDNG WAYS TO CURE WRINKLES AND BLEMISHES \n");
    printf(" PRESS 4 FOR FINDNG WAYS TO CURE SIGNS OF PREMATURE AGEING \n ");
    int c;
    scanf("%d",&c);
   if(c==1)
   {

    printf(" Choose an anti-acne cleanser that has a gentle cleansing action.\n ");
    printf(" Include toner to refine enlarged pores.\n ");
    printf(" Include anti-acne face serum. ...\n ");
    printf(" Moisturize skin to control excessive oil production.\n ");
    printf(" Incorporate sunscreen to avoid the exacerbation of acne and post-acne scars.\n ");

}
else if(c==2)
{
    system("COLOR 60");
char a[1];
   printf("Sun protection can help fade melasma and prevent it from returning \n ");
   printf("Hydroquinone: This is a common treatment for melasma.\n ");
   printf("Tretinoin and a mild corticosteroid: This combination contains a retinoid and an anti-inflammatory, which can even out skin tone\n ");

   printf("ENTER E IF YOU HAVE PRIOR EXPERIENCE OF USING the aforestated products");
     printf("  ENTER N IF YOU ARE A NEWBIE ");
     scanf("%s",a);
     if(a[0]=='E')
     {
         system("COLOR E1");
          printf("0.05 to 1.00% concentration recommended for Hydroquinone  ");
     }
    else if(a[0]=='N')
     {
          printf("0.025% concentration recommended for Tretinoin or Hydroquinon");
     }
     else
        {
            printf(" INVALID INPUT\nTRY AGAIN  ");
     }
   }
   else if(c==3)
   {
printf("  If you're working with combination skin plus frequent breakouts, try the extra steps below.\n ");
printf("Use a cleanser that contains salicylic acid. \n ");
printf(" Double-cleanse at night if you wear makeup.\n ");
printf(" Use a toner to remove excess oil and help fight blackheads and blemishes.\n ");
   }
   else if(c==4)
{
     printf(" There are several lifestyle habits that can help slow down premature aging:\n \033[0m\n ");
      printf(" Eat a healthy, well-balanced diet: Avoid eating too much sugar or refined carbohydrates \033[0m\n ");
       printf("  Protect your skin from the sun: Wear sunscreen with at least SPF 30 every day\033[0m\n ");
        printf(" Exercise most days of the week: Regular physical activity improves circulation and boosts your immune system \033[0m\n ");
         printf(" Sleep well: Maintaining optimal sex hormone levels\033[0m\n ");
          printf(" Drink less alcohol: Alcohol causes premature aging of your skin  \033[0m\n ");
           printf(" Stay hydrated \033[0m\n ");
    printf(" Your medical provider can give guidance on what is best for your situation.  \033[0m\n ");
    printf(" This information does not constitute medical advice or diagnosis.  \033[0m\n ");
}
else
{
  printf(" \033[1;31 INVALID ENTRY \n TRY AGAIN \033[0m\n ");
   }

}
else if(s==4)
{
system("COLOR E4");
printf(" How is sensitive skin treated? \n");
printf(" Avoid taking very hot showers. \n ");
printf("  Choose sensitive skin body wash, face wash and moisturizer, as well as sunscreen formulated for sensitive skin\n ");
printf(" Avoid perfumes.\n ");
printf(" Avoid scented beauty products and laundry detergents.\n ");
printf("  Apply moisturizer regularly to prevent dry skin\n ");
int c;
printf("                     \nTHEY SAY PERFECTION IS A MYTH  \n    ");
    printf("        HERE'S HOW YOU CAN OVERCOME YOUR SKIN IMPERFECTIONS: \n ");
    printf(" PRESS 1 FOR FINDNG WAYS TO CURE HORMONAL ACNE OR PIMPLES \n ");
    printf(" PRESS 2 FOR FINDNG WAYS TO CURE MELASMA\n");
    printf(" PRESS 3 FOR FINDNG WAYS TO CURE WRINKLES AND BLEMISHES \n");
    printf(" PRESS 4 FOR FINDNG WAYS TO CURE SIGNS OF PREMATURE AGEING \n ");
    scanf("%d",&c);
   if(c==1)
   {
       system("COLOR F3");
       printf("Stay Away From Harsh Scrubs. \n");
       printf("You might be tempted to scrub away at your skin to banish blackheads and breakouts. ...Y\n");
       printf("Don't Use Too Many Products at Once. ... \n");
       printf(" Slowly Introduce New Products. ...\n");
       printf(" Beware of Leave-On Treatments. ...\n");
       printf("See a Dermatologist. \n");
   }
   else if(c==2)
   {
       system("COLOR 3F");
char a[1];
   printf("Sun protection can help fade melasma and prevent it from returning \n ");
   printf("Hydroquinone: This is a common treatment for melasma.\n ");
   printf("Tretinoin and a mild corticosteroid: This combination contains a retinoid and an anti-inflammatory, which can even out skin tone\n ");

   printf("ENTER E IF YOU HAVE PRIOR EXPERIENCE OF USING the aforestated products");
     printf("  ENTER N IF YOU ARE A NEWBIE ");
     scanf("%s",a);
     if(a[0]=='E')
     {
         system("COLOR E1");
          printf("0.05 to 1.00% concentration recommended for Hydroquinone  ");
     }
    else if(a[0]=='N')
     {
          printf("0.025% concentration recommended for Tretinoin or Hydroquinon");
     }
     else
        {
            printf(" INVALID INPUT\nTRY AGAIN  ");
     }
   }
       else if(c==3)
{
    system("COLOR E9");
    printf(" Wash your face: Wash your face twice a day, and again after sweating. \n ");
    printf(" Use gentle products: Avoid hot water, and use gentle cleansing devices. \n ");
    printf(" Avoid touching your face: Popping pimples can trap oil, sebum, and bacteria. \n ");
    printf(" Use oil-free products: Use oil-free and non-comedogenic skincare and makeup products.\n ");
    printf(" Use salicylic acid: Salicylic acid can break down dead skin cells, penetrate pores, and clear out dirt and debris. \n ");
    printf(" \033[1;31 Use retinol: Retinol can help regulate sebum production in oily skin, reducing the likelihood of clogged pores. \n");
    printf(" Use acne treatments: Use an acne treatment recommended by your dermatologist.\n ");
     printf("\n Your medical provider can give guidance on what is best for your situation. \n ");
    printf(" This information does not constitute medical advice or diagnosis.  \n ");
}
else if(c==4)
{
    system("COLOR C0");

 printf("  Protect your skin from the sun every day. ...\n ");
  printf(" Apply self-tanner rather than get a tan. ...\n ");
   printf(" If you smoke, stop.\n ");
    printf(" Cleanse your skin gently\n ");
     printf(" Regular exercise lowers stress and improves sleep, skin and bone health, and mood. \n ");
      printf(" Consider antioxidants and peptides.\n ");
           printf(" Stay hydrated \033[0m\n ");
    printf(" Your medical provider can give guidance on what is best for your situation.  \033[0m\n ");
    printf(" This information does not constitute medical advice or diagnosis.  \033[0m\n ");
}
   }

else
{
    system("COLOR E9");
   printf(" \033[1;31m INVALID INPUT\nTRY AGAIN \033[0m\n ");
}

}


void BMI(float weight,float height)

{


    float bmi = weight / (height * height);
    printf("\033[1;33m\nYour Body Mass Index(BMI) is %f\n", bmi);
    if(bmi < 15)
    {

        printf("Your BMI category is: Starvation\n");

        printf("1. Eat nutrient-dense foods such as lean proteins, whole grains,healthy fats, fruits and vegetables.\n2. Increase your portion sizes at meals to ensure you are consuming more calories.\n3. Engage in strength training to build muscle mass.\n4. Avoid empty calories by minimizing foods and drinks with added sugars.\n5. Drink plenty of water.");

    }
    else if(bmi >= 15.1 && bmi <= 17.5)
    {

        printf("Your BMI category is: Anorexic\n");

        printf("1. Eat nutrient-dense foods such as lean proteins, whole grains,healthy fats, fruits and vegetables.\n2. Increase your portion sizes at meals to ensure you are consuming more calories.\n3. Engage in strength training to build muscle mass.\n4. Avoid empty calories by minimizing foods and drinks with added sugars.\n5. Drink plenty of water.");
    }
    else if(bmi >= 17.6 && bmi <= 18.5)
    {

        printf("Your BMI category is: Underweight\n");

        printf("1. Eat nutrient-dense foods such as lean proteins, whole grains,healthy fats, fruits and vegetables.\n2. Increase your portion sizes at meals to ensure you are consuming more calories.\n3. Engage in strength training to build muscle mass.\n4. Avoid empty calories by minimizing foods and drinks with added sugars.\n5. Drink plenty of water.");

    }
    else if(bmi >= 18.6 && bmi <= 24.9)
    {

        printf("Your BMI category is: Ideal\n");

    }
    else if(bmi >= 25 && bmi <= 25.9)
    {

        printf("Your BMI category is: Overweight\n1. Eat a balanced, calorie-controlled diet.\n2. Take up activities such as fast walking, jogging, swimming or playing preferred outdoor game for 150 to 300 minutes (two and-a-half to five hours) a week.\n3. Improve your sleep cycle.\n4. Enjoy doing your hobbies to reduce stress.\n5. Limit your screen time.\nFurther Assess");

    }
    else if(bmi >= 30 && bmi <= 30.9)
    {

        printf("Your BMI category is: Obese\n1. Eat a balanced, calorie-controlled diet.\n2. Take up activities such as fast walking, jogging, swimming or playing preferred outdoor game for 150 to 300 minutes (two and-a-half to five hours) a week.\n3. Improve your sleep cycle.\n4. Enjoy doing your hobbies to reduce stress.\n5. Limit your screen time.\nFurther Assess");

    }
    else if(bmi >= 40)
    {

        printf("Your BMI category is: Morbidly Obese\n1. Eat a balanced, calorie-controlled diet.\n2. Take up activities such as fast walking, jogging, swimming or playing preferred outdoor game for 150 to 300 minutes (two and-a-half to five hours) a week.\n3. Improve your sleep cycle.\n4. Enjoy doing your hobbies to reduce stress.\n5. Limit your screen time.\nFurther Assess");

    }
    else
    {

        printf("Wrong entry\n");

    }

}

void CreateAccount()
{

        n++;

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("\nInput your name(with underscore in place of spaces):\n");

        scanf("%s",&people[n].name);

    printf("\nInput your age:\n");

        scanf("%d",&people[n].age);

    printf("\nInput your weight:\n");

        scanf("%f",&people[n].weight);

    printf("\nInput your height(in cm):\n");

        scanf("%f",&people[n].height);

    people[n].height/=100;

    printf("\nInput your Gender:\n");

    fflush(stdin);

        scanf("%c",&people[n].Gender);

    printf("\nInput your Blood Group:\n");

    fflush(stdin);

        scanf("%s",&people[n].B);

    printf("Your pass code number:%d\n",n);
     FILE* data;
    if ( (data = fopen("data.bin", "wb")) == NULL )
    {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(people, sizeof(struct person) * 50, 1, data);
    fclose(data);
}
void login()
{
    int n;

    FILE* data;
        if ((data = fopen("data.bin", "rb")) == NULL)
        {
        printf("Error opening file\n");
        return 1;
        }


    fread(people, sizeof(struct person) * 50, 1, data);



    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("\033[1;35m\nEnter your pass code number:");

    scanf("%d",&n);
    float w=people[n].weight,h=people[n].height;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("Your We Care Profile is as follows:\n************************************************************\n\033[0m\n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

     printf("\033[1;37m\nYour name\n");

printf("%s\n",people[n].name);

printf("Your age(in years)\n");

printf("%d",people[n].age);

printf("\nYour weight(in kg)\n");

printf("%f",people[n].weight);

printf("\nYour height(in m)\n");

printf("%f",people[n].height);

printf("\nYour Gender\n");

printf("%c",people[n].Gender);

printf("\nYour Blood Group\n");

printf("%s",people[n].B);
printf( "\n DO YOU KNOW ?\nThe liquid part of yogurt that sometimes separates on top, the whey, contains important nutrients such as calcium, potassium, and protein.\nDon’t drain it, mix it.\n");
 BMI(w,h);
 printf("\nThe Login-Logout Interface,Body Mass Index Classification Department :}\n");
 getch();
 system("cls");
 printf( "\nDO YOU KNOW?\nYour pets should never eat raisins, grapes, macadamia nuts or chocolate.\n");
 skin();
 printf("\nThe Skin Care Department  :}");
 getch();
 system("cls");
 printf( "\nDO YOU KNOW?\nEating fairly large amounts of raisins and grapes can cause kidney failure in dogs\n\n");
 DEV();
 printf("\nThe Blood Group Department and the Calorie System :}");
 getch();
 system("cls");
 routine();
 printf("\nThe Wellness Routine Department :}");
 getch();
 system("cls");
fclose(data);
}
void routine(){
//Dishing out a wellness routine for the customers on             Nearby gym following chest-back-legs-shoulders-chest-back
//the basis of their requirements.                                TIME FOR CALISTHENICS     Home gym following chest-back-legs-shoulders-chest-back
int n1,n2,n3,name,t,i,j;//name belongs to the name of the active user.
printf("\033[1;35mHello\nWelcome to the new section of our We care\033[0m\n");
printf("\033[1;32m-----------------------------------------------------------------------------------------------------------------------\033[0m\n");
printf("\033[1;33mLet us know what requirements u want to see in your body\033[0m\n");
printf("\033[1;33mPress 1 for cutting body weight\nPress 2 for gaining weight \nPress 3 for maintaining\033[0m\nYOUR RESPONSE->");
scanf("%d",&n1);
printf("\033[1;32m-----------------------------------------------------------------------------------------------------------------------\033[0m\n");
printf("\033[1;33mPress 1 for going Vegan \nPress 2 for going veg \nPress 3 for going omni\033[0m\nYOUR RESPONSE->");
scanf("%d",&n2);
printf("\033[1;32m-----------------------------------------------------------------------------------------------------------------------\033[0m\n");
printf("\033[1;33mPress 1 for including gym \nPress 2 for including calisthenics \nPress 3 for including home gym\033[0m\nYOUR RESPONSE->");
scanf("%d",&n3);

printf("\033[1;32m-----------------------------------------------------------------------------------------------------------------------\033[0m\n");
printf("\033[1;33mWhat are your working hours incl time to travel\033[0m\n");
printf("\033[1;33mPress 1 for 8 am to 6pm \nPress 2 for 10 pm to 8 pm\033[0m\nYOUR RESPONSE->");
scanf("%d",&t);
printf("\033[1;32m-----------------------------------------------------------------------------------------------------------------------\033[0m\n");
if(t==1){
if(n1==1&&n2==1&&n3==1)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breakfast including cereals,dry fruits,oats.\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,low carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==1&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breakfast including  cereals,dry fruits,oats.\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,low carbs diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==1&&n3==3)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breakfast including  cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,low carb diet.\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==2&&n3==1)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,high carb diet,100gm of paneer\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==2&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,low carb diet,50 gm of paneer.\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==2&&n3==3)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,low carb diet,50 gm of protein\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==3&&n3==1)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,low carb diet,100gm chichken breast\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==3&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,low carb diet,100gm chichken breast\n11-12 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==3&&n3==3)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,low carb diet,100gm chichken breast\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==1&&n3==1)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins, high carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==1&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS \n10-11pm Dinner having proteins high carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==1&&n3==3)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,high carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==2&&n3==1)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including  cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,high carb diet,100gm of paneer.\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==2&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including  cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,high carb diet,100gm of paneer.\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==2&&n3==3)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,high carb diet,100 gm of paneer\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==3&&n3==1)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,high carb diet,250gm chichken breast\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==3&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,high carb diet,250gm chichken breast\n11-12 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==3&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,high carb diet,250gm chichken breast\n11-12 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==1&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,med carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==1&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,med carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==1&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,med carb diet\n11-12 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==2&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,med carb diet,150gm of paneer\n11-12 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==2&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,med carb diet,150gm of paneer\n11-12 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==2&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,med carb diet,150 gm of paneer.\n11-12 Time for hobby\033[0m\n");
}else if(n1==3&&n2==3&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Nearby gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,med carb diet,150gm chichken breast\n11-12 Time for hobby\033[0m\n");
}else if(n1==3&&n2==3&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm TIME FOR CALISTHENICS\n10-11pm Dinner having proteins,med carb diet,250gm chichken breast\n11-12 Time for hobby\033[0m\n");
  }
else if(n1==3&&n2==3&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-7am Freshup and bath also get ready for job\n7-8am Breaksfast including cereals,dry fruits,omlette\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 8-6PM***\033[0m\n");

  printf("\033[1;35m6-8Pm A nice sleep and rest\n8-10Pm Home gym following chest-back-legs-shoulders-chest-back\n10-11pm Dinner having proteins,med carb diet,250gm chichken breast\n11-12 Time for hobby\033[0m\n");
}}
if(t==2)
{
if(n1==1&&n2==1&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");

  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==1&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");

  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==1&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am  Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");

  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==2&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");

  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet,100 gm paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==2&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");

  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");

  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet,100 gm of paneer.\n10-11pm Time for hobby\033[0m\n");
}
else if(n1==1&&n2==2&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet,100 gm of paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==3&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet,100gm chichken breast\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==3&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette \033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet,100gm chichken breast\n10-11 Time for hobby\033[0m\n");
}
else if(n1==1&&n2==3&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,low carb diet,100gm chichken breast\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==1&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==1&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==1&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==2&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet,250 gm of paneer.\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==2&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet,250 gm of paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==2&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet,250 gm of paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==3&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet,250gm chichken breast\n10-11 Time for hobby\033[0m\n");
}
else if(n1==2&&n2==3&&n3==2)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet,250gm chichken breast\n10-11 Time for hobby\033[0m\n");
  }
else if(n1==2&&n2==3&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,high carb diet,250gm chichken breast\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==1&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==1&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==1&&n3==3)
{
  printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,oats\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==2&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m----***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet,150 gm of paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==2&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet,150 gm of paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==2&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,banana,bread peanut butter,milk\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10 Dinner having proteins,med carb diet,150 gm of paneer\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==3&&n3==1)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Nearby gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet,150gm chichken breast\n10-11 Time for hobby\033[0m\n");
}else if(n1==3&&n2==3&&n3==2)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am TIME FOR CALISTHENICS\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet,150gm chichken breast\n10-11 Time for hobby\033[0m\n");
}
else if(n1==3&&n2==3&&n3==3)
{
printf("\033[1;35mWakeup at 5Am\n5-6am Running and stretching\n6-8am Home gym following chest-back-legs-shoulders-chest-back\n8-9am Freshup and bath also get ready for job\n9-10am Breaksfast including cereals,dry fruits,omlette\033[0m\n");
  printf("\033[1;33m***JOB TIMINGS FROM 10-8PM***\033[0m\n");
  printf("\033[1;35m8-9Pm A nice sleep and rest\n9-10pm Dinner having proteins,med carb diet,150gm chichken breast\n10-11 Time for hobby\033[0m\n");}}
printf("\033[1;32m-----------------------------------------------------------------------------------------------------------------------\033[0m\n");}

// Driver Code
int main()
{

    int i;
    int a;
    int b;
    int choice;
    int n=0;

    printf("\n");
    printf("\n");
    char figlet2[] = "\033[40m\t\t888       888 8888888888       .d8888b.        d8888 8888888b.  8888888888 \n\t\t888   o   888 888             d88P  Y88b      d88888 888   Y88b 888        \n\t\t888  d8b  888 888             888    888     d88P888 888    888 888        \n\t\t888 d888b 888 8888888         888           d88P 888 888   d88P 8888888    \n\t\t888d88888b888 888             888          d88P  888 8888888P\"  888        \n\t\t88888P Y88888 888             888    888  d88P   888 888 T88b   888        \n\t\t8888P   Y8888 888             Y88b  d88P d8888888888 888  T88b  888        \n\t\t888P     Y888 8888888888       \"Y8888P\" d88P     888 888   T88b 8888888888 \033[0m";
    printf(figlet2);
    printf("\n");
    printf("\n");


    printf("\033[1;33m                                  WELCOME TO *WE CARE* VIRTUAL HEALTHCARE ASSISTANT\n\n                            \033[0m");

    printf("\n");

    printf("\033[1;35m*********************************************************************************************************************");
    printf("\nIntroduction: One of the most common problems faced by today's people is a lack of knowledge of diseases and a lack of immediate first aid consultation.");
    printf("\nDue to this many people may suffer from physical and mental stress as they try to figure out the reason for their condition.");
    printf(" \nIn some cases, they even lose their lives and common diseases become life-threatening.");
     printf("\nNow Virtual Health Assistant comes into action.");
    printf(" \nIt is a service in which the proposed system tries to eliminate users’ need to figure out their disease by giving them ");
     printf("\naccess to a centralized clinical repository in a much interactive manner. ");

 printf("\033[1;35m*********************************************************************************************************************");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    for(int i=0;choice!=3;i++)
        {
             printf("\033[1;32m\n\nENTER YOUR CHOICE..\n1.Create Account\n2.LOGIN\n3.EXIT\033[0m\n");

                scanf("%d",&choice);
                  printf("\nPress Enter to come to the next screen===>");

        getch();
   system("cls");

    interface(choice);

  printf("\nPress Enter to come to the next screen===>");

  getch();

  system("cls");

    }

}

void interface(int choice)

{

      switch (choice)

      {

    case 1:

        CreateAccount();

         break;

    case 2:

        login();

        break;

    case 3:

        exit(0);

        break;
    }

}

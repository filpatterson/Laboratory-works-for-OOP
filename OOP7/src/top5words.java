public class top5words {
    String firstPlace, secondPlace, thirdPlace, fourthPlace, fifthPlace;
    int firstAmount, secondAmount, thirdAmount, fourthAmount, fifthAmount;

    public top5words(){}

    public void setPos(String someWord, int someAmount, int choice){
        switch(choice){
            case 1:
                this.firstPlace = someWord;
                this.firstAmount = someAmount;
                break;
            case 2:
                this.secondPlace = someWord;
                this.secondAmount = someAmount;
                break;
            case 3:
                this.thirdPlace = someWord;
                this.thirdAmount = someAmount;
                break;
            case 4:
                this.fourthPlace = someWord;
                this.fourthAmount = someAmount;
                break;
            case 5:
                this.fifthPlace = someWord;
                this.fifthAmount = someAmount;
                break;
            default:
                System.out.println("There is no such variant!");
                return;
        }
    }

    public String getWord(int choice){
        switch(choice){
            case 1:
                return this.firstPlace;
            case 2:
                return this.secondPlace;
            case 3:
                return this.thirdPlace;
            case 4:
                return this.fourthPlace;
            case 5:
                return this.fifthPlace;
            default:
                return "There is no value!";
        }
    }

    public int getValue(int choice){
        switch(choice){
            case 1:
                return this.firstAmount;
            case 2:
                return this.secondAmount;
            case 3:
                return this.thirdAmount;
            case 4:
                return this.fourthAmount;
            case 5:
                return this.fifthAmount;
            default:
                return 0;
        }
    }
}

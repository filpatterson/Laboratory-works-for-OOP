package com.bender;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Bender {

    public static void main(String[] args) {
        Path wiki_path = Paths.get("C:/temp", "three_expressions.txt");

        Charset charset = Charset.forName("ISO-8859-1");
        try {
            List<String> brackets = new ArrayList<String>();
            List<String> lines = Files.readAllLines(wiki_path, charset);

            for (String line : lines) {
                System.out.println(line);
                for (int i = 0; i < line.length(); i++) {
                    if (line.charAt(i) == '(')
                        brackets.add("(");
                    if (line.charAt(i) == ')')
                        brackets.remove("(");
                }

                if(brackets.isEmpty())
                    System.out.println("All brackets are closed");
                else
                    System.out.println("Some are not closed");

                while(!brackets.isEmpty()){
                    brackets.remove("(");
                }
            }

        } catch (IOException e) {
            System.out.println(e);
        }

    }
}
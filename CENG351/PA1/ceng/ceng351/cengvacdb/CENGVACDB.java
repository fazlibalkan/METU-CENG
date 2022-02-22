package ceng.ceng351.cengvacdb;

import java.sql.*;
import java.util.ArrayList;

public class CENGVACDB implements ICENGVACDB {

    private static String user = "e2380178"; // TODO: Your userName
    private static String password = "RzIt?bX3jJaE"; //  TODO: Your password
    private static String host = "144.122.71.121"; // host name
    private static String database = "db2380178";
    private static int port = 8080; // port

    private static Connection connection = null;

    @Override
    public void initialize() {
        String url = "jdbc:mysql://" + host + ":" + port + "/" + database + "?useSSL=false";

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection =  DriverManager.getConnection(url, user, password);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public int createTables() {
        int num = 0;
        String createUser = "CREATE TABLE User (" + "userID INT NOT NULL, "
                + "userName VARCHAR(30), "
                + "age INT, "
                + "address VARCHAR(150), "
                + "password VARCHAR(30), "
                + "status VARCHAR(15), "
                + "PRIMARY KEY (userID)" + ")";

        try{
            Statement statement = connection.createStatement();
            statement.executeUpdate(createUser);
            statement.close();
            num++;
        } catch (SQLException e){
            e.printStackTrace();
        }

        String createVaccine = "CREATE TABLE Vaccine (" + "code INT NOT NULL, "
                + "vaccinename VARCHAR(30), "
                + "type VARCHAR(30), "
                + "PRIMARY KEY (code)" + ")";

        try{
            Statement statement = connection.createStatement();
            statement.executeUpdate(createVaccine);
            statement.close();
            num++;
        } catch (SQLException e){
            e.printStackTrace();
        }

        String createVaccination = "CREATE TABLE Vaccination (" + "code INT NOT NULL, "
                + "userID INT NOT NULL, "
                + "dose INT NOT NULL, "
                + "vacdate DATE, "
                + "PRIMARY KEY (code, userID, dose), "
                + "FOREIGN KEY (code) REFERENCES Vaccine (code), "
                + "FOREIGN KEY (userID) REFERENCES User (userID)" + ")";

        try{
            Statement statement = connection.createStatement();
            statement.executeUpdate(createVaccination);
            statement.close();
            num++;
        } catch (SQLException e){
            e.printStackTrace();
        }

        String createAllergicSideEffect = "CREATE TABLE AllergicSideEffect (" + "effectcode INT NOT NULL,"
                + "effectname VARCHAR(50), "
                + "PRIMARY KEY (effectcode)" + ")";

        try{
            Statement statement = connection.createStatement();
            statement.executeUpdate(createAllergicSideEffect);
            statement.close();
            num++;
        } catch (SQLException e){
            e.printStackTrace();
        }

        String createSeen = "CREATE TABLE Seen(" + "effectcode INT NOT NULL,"
                + "code INT NOT NULL, "
                + "userID INT NOT NULL, "
                + "date INT, "
                + "degree VARCHAR(30), "
                + "PRIMARY KEY (effectcode, code, userID), "
                + "FOREIGN KEY (effectcode) REFERENCES AllergicSideEffect (effectcode), "
                + "FOREIGN KEY (code) REFERENCES Vaccination (code) ON DELETE CASCADE , " //CHECKKKKKK!!!!!!!
                + "FOREIGN KEY (userID) REFERENCES User(userID)" + ")";

        try{
            Statement statement = connection.createStatement();
            statement.executeUpdate(createSeen);
            statement.close();
            num++;
        } catch (SQLException e){
            e.printStackTrace();
        }

        return num;
    }

    @Override
    public int dropTables() {
        int num = 0;
        String[] NamesOfTheTables = {"Seen", "AllergicSideEffect", "Vaccination", "Vaccine", "User"};

        for (String s:
             NamesOfTheTables) {
            try {
                Statement statement = connection.createStatement();
                statement.executeUpdate("DROP TABLE IF EXISTS " + s);
                statement.close();
                num++;
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return num;
    }

    @Override
    public int insertUser(User[] users) {
        int num = 0;

        for (User u:
             users) {
            try {
                int userID = u.getUserID();
                String userName = u.getUserName();
                int age = u.getAge();
                String address = u.getAddress();
                String password = u.getPassword();
                String status = u.getStatus();

                String query = "INSERT INTO User (userID, userName, age, address, password, status) "
                        + " VALUES ( " + userID + ", \"" + userName + "\", " + age + ", \"" + address + "\", \"" + password + "\", \"" + status + "\" );";

                Statement statement = connection.createStatement();
                statement.executeUpdate(query);
                num++;
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
        return num;
    }

    @Override
    public int insertAllergicSideEffect(AllergicSideEffect[] sideEffects) {
        int num = 0;

        for (AllergicSideEffect ase:
                sideEffects) {
            try {
                int effectcode = ase.getEffectCode();
                String effectname = ase.getEffectName();

                String query = "INSERT INTO AllergicSideEffect (effectcode, effectname) "
                        + " VALUES ( " + effectcode + ", \"" + effectname + "\"" + ");" ;

                Statement statement = connection.createStatement();
                statement.executeUpdate(query);
                num++;
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
        return num;
    }

    @Override
    public int insertVaccine(Vaccine[] vaccines) {
        int num = 0;

        for (Vaccine v:
                vaccines) {
            try {
                int code = v.getCode();
                String vaccinename = v.getVaccineName();
                String type = v.getType();

                String query = "INSERT INTO Vaccine (code, vaccinename, type) "
                        + " VALUES ( " + code + ", \"" + vaccinename + "\", \"" + type + "\"" + ");" ;

                Statement statement = connection.createStatement();
                statement.executeUpdate(query);
                num++;
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
        return num;
    }

    @Override
    public int insertVaccination(Vaccination[] vaccinations) {
        int num = 0;

        for (Vaccination v:
                vaccinations) {
            try {
                int code = v.getCode();
                int userID = v.getUserID();
                int dose = v.getDose();
                String vacdate = v.getVacdate();

                String query = "INSERT INTO Vaccination (code, userID, dose, vacdate) "
                        + " VALUES ( " + code + ", " + userID + ", " + dose + ", \"" + vacdate + "\"" + ");" ;

                Statement statement = connection.createStatement();
                statement.executeUpdate(query);
                num++;
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
        return num;
    }

    @Override
    public int insertSeen(Seen[] seens) {
        int num = 0;

        for (Seen s:
                seens) {
            try {
                int effectcode = s.getEffectcode();
                int code = s.getCode();
                String userID = s.getUserID();
                String date = s.getDate();
                String degree = s.getDegree();

                String query = "INSERT INTO Seen (effectcode, code, userID, date, degree) "
                        + " VALUES ( " + effectcode + ", " + code + ", \"" + userID + "\", " + date +  ", \"" + degree + "\"" + ");" ;

                Statement statement = connection.createStatement();
                statement.executeUpdate(query);
                num++;
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }

        }
        return num;
    }

    @Override
    public Vaccine[] getVaccinesNotAppliedAnyUser() {

        String query = "SELECT V.code, V.vaccinename, V.type "
                     + "FROM Vaccine V "
                     + "WHERE V.code NOT IN (SELECT V.code " +
                                            "FROM Vaccination Vn, Vaccine V " +
                                            "WHERE Vn.code = V.code) ORDER BY V.code";

        ResultSet resultSet;
        ArrayList<Vaccine> vaccines = new ArrayList<Vaccine>();

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int code = resultSet.getInt("code");
                String vaccinename = resultSet.getString("vaccinename");
                String type = resultSet.getString("type");

                vaccines.add(new Vaccine(code, vaccinename, type));
            }

            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        Vaccine[] vaccinesArray = new Vaccine[vaccines.size()];
        vaccinesArray = vaccines.toArray(vaccinesArray);


        return vaccinesArray;
    }

    @Override
    public QueryResult.UserIDuserNameAddressResult[] getVaccinatedUsersforTwoDosesByDate(String vacdate) {

        String query = "SELECT U.userID, U.userName, U.address "
                + "FROM User U "
                + "WHERE U.userID IN (SELECT Vn.userID " +
                        " FROM Vaccination Vn " +
                        " WHERE Vn.vacdate >= \""+ vacdate +
                        "\" GROUP BY (Vn.userID) " +
                        " HAVING COUNT(*) = 2) ORDER BY U.userID";

        ResultSet resultSet;

        ArrayList<QueryResult.UserIDuserNameAddressResult> QueryResultList = new ArrayList<QueryResult.UserIDuserNameAddressResult>();

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int userID = resultSet.getInt("userID");
                String userName = resultSet.getString("userName");
                String address = resultSet.getString("address");


                QueryResultList.add(new QueryResult.UserIDuserNameAddressResult(Integer.toString(userID), userName, address));

            }
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.UserIDuserNameAddressResult[] QueryResultArray = new QueryResult.UserIDuserNameAddressResult[QueryResultList.size()];
        QueryResultArray = QueryResultList.toArray(QueryResultArray);
        return QueryResultArray;
    }

    //YAPILMADI
    @Override
    public Vaccine[] getTwoRecentVaccinesDoNotContainVac() {
        String query = "SELECT Temp.code, Temp.vaccinename, Temp.type" +
                        " FROM (SELECT V.code, V.vaccinename, V.type, Vn.vacdate" +
                                " FROM Vaccine V, Vaccination Vn" +
                                " WHERE V.code = Vn.code " +
                                        " AND V.vaccinename NOT LIKE \"%VAC%\" ORDER BY Vn.vacdate DESC ) AS Temp";

        ResultSet resultSet;
        ArrayList<Vaccine> vaccines = new ArrayList<Vaccine>();
        int sec = 0;
        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            resultSet.next();
            int code = resultSet.getInt("code");
            String vaccinename = resultSet.getString("vaccinename");
            String type = resultSet.getString("type");
            vaccines.add(new Vaccine(code, vaccinename, type));

            while (resultSet.next()) {
                if (resultSet.getInt("code") == code) {
                    continue;
                } else{
                    code = resultSet.getInt("code");
                    vaccinename = resultSet.getString("vaccinename");
                    type = resultSet.getString("type");
                    vaccines.add(new Vaccine(code, vaccinename, type));
                    break;
                }
            }

            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        Vaccine[] vaccinesArray = new Vaccine[vaccines.size()];
        vaccinesArray = vaccines.toArray(vaccinesArray);


        return vaccinesArray;

    }

    @Override
    public QueryResult.UserIDuserNameAddressResult[] getUsersAtHasLeastTwoDoseAtMostOneSideEffect() {
        String AtLeastTwoDose = "SELECT V.userID" +
                                " FROM Vaccination V " +
                                " GROUP BY V.userID" +
                                " HAVING COUNT(*) > 1";

        String AtMostOneSideEffect = "SELECT S.userID" +
                                    " FROM Seen S " +
                                    " GROUP BY S.userID" +
                                    " HAVING COUNT(*) > 1";

        String query = "SELECT U.userID, U.userName, U.address " +
                        " FROM User U " +
                        " WHERE U.userID IN (" + AtLeastTwoDose + ") " +
                            " AND U.userID NOT IN (" + AtMostOneSideEffect + ") ORDER BY U.userID";

        ResultSet resultSet;

        ArrayList<QueryResult.UserIDuserNameAddressResult> QueryResultList = new ArrayList<QueryResult.UserIDuserNameAddressResult>();

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int userID = resultSet.getInt("userID");
                String userName = resultSet.getString("userName");
                String address = resultSet.getString("address");


                QueryResultList.add(new QueryResult.UserIDuserNameAddressResult(Integer.toString(userID), userName, address));

            }
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.UserIDuserNameAddressResult[] QueryResultArray = new QueryResult.UserIDuserNameAddressResult[QueryResultList.size()];
        QueryResultArray = QueryResultList.toArray(QueryResultArray);
        return QueryResultArray;
    }

    @Override
    public QueryResult.UserIDuserNameAddressResult[] getVaccinatedUsersWithAllVaccinesCanCauseGivenSideEffect(String effectname) {
        String AllVaccinesWithGivenSideEffect = "SELECT DISTINCT S.code" +
                                                " FROM Seen S, AllergicSideEffect ASE" +
                                                " WHERE S.effectcode = ASE.effectcode" +
                                                " AND ASE.effectname = \"" + effectname.replaceAll(" ", "_") + "\"";

        String query = "SELECT U.userID, U.userName, U.address" +
                        " FROM User U" +
                        " WHERE NOT EXISTS (SELECT Av.code" +
                                            " FROM ("+ AllVaccinesWithGivenSideEffect +")  AS Av" +
                                             " WHERE NOT EXISTS ( SELECT S.code" +
                                                                " FROM Seen S" +
                                                                " WHERE S.code = Av.code" +
                                                                "  AND S.userID = U.userID)) ORDER BY U.userID;";

        ResultSet resultSet;

        ArrayList<QueryResult.UserIDuserNameAddressResult> QueryResultList = new ArrayList<QueryResult.UserIDuserNameAddressResult>();

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int userID = resultSet.getInt("userID");
                String userName = resultSet.getString("userName");
                String address = resultSet.getString("address");


                QueryResultList.add(new QueryResult.UserIDuserNameAddressResult(Integer.toString(userID), userName, address));

            }
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.UserIDuserNameAddressResult[] QueryResultArray = new QueryResult.UserIDuserNameAddressResult[QueryResultList.size()];
        QueryResultArray = QueryResultList.toArray(QueryResultArray);
        return QueryResultArray;
    }

    @Override
    public QueryResult.UserIDuserNameAddressResult[] getUsersWithAtLeastTwoDifferentVaccineTypeByGivenInterval(String startdate, String enddate) {

        String query = "SELECT U.userID, U.userName, U.address" +
                        " FROM User U" +
                        " WHERE U.userID IN (SELECT Vn1.userID" +
                                            " FROM Vaccination Vn1, Vaccine V1, Vaccination Vn2, Vaccine V2 " +
                                            " WHERE Vn1.userID = Vn2.userID" +
                                                " AND Vn1.code = V1.code AND Vn2.code = V2.code" +
                                                " AND V1.type <> V2.type" +
                                                " AND Vn1.vacdate >= \"" + startdate + "\" AND Vn1.vacdate <= \"" + enddate +
                                                "\" AND Vn2.vacdate >= \"" + startdate + "\" AND Vn2.vacdate <= \"" + enddate + "\") ORDER BY U.userID";

        ResultSet resultSet;

        ArrayList<QueryResult.UserIDuserNameAddressResult> QueryResultList = new ArrayList<QueryResult.UserIDuserNameAddressResult>();

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            while (resultSet.next()) {
                int userID = resultSet.getInt("userID");
                String userName = resultSet.getString("userName");
                String address = resultSet.getString("address");


                QueryResultList.add(new QueryResult.UserIDuserNameAddressResult(Integer.toString(userID), userName, address));

            }
            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        QueryResult.UserIDuserNameAddressResult[] QueryResultArray = new QueryResult.UserIDuserNameAddressResult[QueryResultList.size()];
        QueryResultArray = QueryResultList.toArray(QueryResultArray);
        return QueryResultArray;
    }

    //less than means?, DISTINCT?
    @Override
    public AllergicSideEffect[] getSideEffectsOfUserWhoHaveTwoDosesInLessThanTwentyDays() {

        String query = "SELECT DISTINCT ASE.effectcode, ASE.effectname" +
                        " FROM AllergicSideEffect ASE, Seen S" +
                        " WHERE ASE.effectcode = S.effectcode" +
                                " AND S.userID IN (SELECT Vn1.userID" +
                                                " FROM Vaccination Vn1, Vaccination Vn2" +
                                                " WHERE Vn1.userID = Vn2.userID" +
                                                        " AND Vn1.code = Vn2.code" +
                                                        " AND Vn1.vacdate > Vn2.vacdate" +
                                                        " AND DATEDIFF(Vn1.vacdate, Vn2.vacdate) < 20) ORDER BY ASE.effectcode";
        ResultSet resultSet;
        ArrayList<AllergicSideEffect> ASEList = new ArrayList<AllergicSideEffect>();

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            while (resultSet.next()){
                int effectcode = resultSet.getInt("effectcode");
                String effectname = resultSet.getString("effectname");

                ASEList.add(new AllergicSideEffect(effectcode, effectname));

            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        AllergicSideEffect[] ASEArray = new AllergicSideEffect[ASEList.size()];
        ASEArray = ASEList.toArray(ASEArray);


        return ASEArray;
    }

    @Override
    public double averageNumberofDosesofVaccinatedUserOverSixtyFiveYearsOld() {
        String userIDDoseCount = "SELECT U.userID, MAX(Vn.dose) as maxDose" +
                        " FROM User U, Vaccination Vn" +
                        " WHERE U.userID = Vn.userID" +
                        " AND U.age >= 65" +
                        " GROUP BY U.userID";

        String query = "SELECT AVG(D.maxDose)" +
                        " FROM (" + userIDDoseCount + ") AS D";

        ResultSet resultSet;
        double result = 0;

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(query);

            resultSet.next();
            result = Double.parseDouble(resultSet.getString(1));

            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

       return result;
    }


    @Override
    public int updateStatusToEligible(String givendate) {
        String lastdose = "SELECT DISTINCT EU.userID" +
                            " FROM ( SELECT U.userID, MAX(Vn.vacdate) AS dateLastDose" +
                                " FROM User U, Vaccination Vn" +
                                " WHERE U.userID = Vn.userID" +
                                " AND U.status = \"Not_Eligible\"" +
                                " GROUP BY U.userID ) AS EU" +
                            " WHERE DATEDIFF(\"" + givendate + "\", EU.dateLastDose) >= 120 ";

        String query = "UPDATE User U" +
                        " SET U.status = \"Eligible\"" +
                        " WHERE U.userID in ( " + lastdose + " )";

        ResultSet resultSet;
        int result = 0;

        try {
            Statement statement = connection.createStatement();
            resultSet = statement.executeQuery(lastdose);

            while (resultSet.next()) {
                result += 1;
            }

            statement.executeUpdate(query);

            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return result;


    }

    // ON DELETE CASCADE ON Seen table?
    @Override
    public Vaccine deleteVaccine(String vaccineName) {
        String query = "DELETE FROM Vaccine V" +
                        " WHERE V.vaccinename = \"" + vaccineName + "\"";


        ResultSet resultSet;
        String vaccine = "SELECT V.code, V.vaccinename, V.type" +
                            " FROM Vaccine V" +
                            " WHERE V.vaccinename = \"" + vaccineName + "\"";

        Vaccine deletedVaccine = null;

        try {
            Statement statement = connection.createStatement();

            resultSet = statement.executeQuery(vaccine);


            while (resultSet.next()) {
                deletedVaccine = new Vaccine(resultSet.getInt("code"), resultSet.getString("vaccinename"), resultSet.getString("type"));
            }



            statement.executeUpdate(query);

            statement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return deletedVaccine;

    }
}

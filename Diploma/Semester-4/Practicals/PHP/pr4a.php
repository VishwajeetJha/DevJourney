<?php
    if ($_POST["car"] == 'Safari' || $_POST["car"] == 'Nexon' || $_POST["car"] == 'Tigor' || $_POST["car"] == 'Tiago')
    {
        echo "The Car ".$_POST["car"]." is Manufractured By: TATA."."<br>";
    }
    elseif ($_POST["car"] == 'XUV700' || $_POST["car"] == 'XUV300' || $_POST["car"] == 'Bolero')
    {
        echo "The Car ".$_POST["car"]." is Manufractured By: Mahindra."."<br>";
    }
    elseif ($_POST["car"] == 'I20' || $_POST["car"] == 'Verna' || $_POST["car"] == 'Venue' || $_POST["car"] == 'Creta')
    {
        echo "The Car ".$_POST["car"]." is Manufractured By: Hyundai."."<br>";
    }
    elseif ($_POST["car"] == 'Swift' || $_POST["car"] == 'Baleno' || $_POST["car"] == 'Brezza')
    {
        echo "The Car ".$_POST["car"]." is Manufractured By: Suzuki."."<br>";
    }
    if($_POST["car"] == 'Safari'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Tata/Safari/11265/1697533880503/front-left-side-47.jpg' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Nexon'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Tata/Nexon/11104/1697698470038/front-left-side-47.jpg'></body></html>";
    }
    elseif($_POST["car"] == 'Tigor'){
        echo "<html><body><img src='https://img.gaadicdn.com/images/carexteriorimages/930x620/Tata/Tigor/10671/1690023500728/front-left-side-47.jpg' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Tiago'){
        echo "<html><body><img src='https://img.gaadicdn.com/images/carexteriorimages/930x620/Tata/Tiago/7338/1660898465523/front-left-side-47.jpg' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'XUV700'){
        echo "<html><body><img src='https://auto.mahindra.com/-/media/project/mahindra/dotcom/mahindra/dark-theme-mahindra-images/gallery/xuv700/photos/popup-images/big01.jpg?rev=77a9d625ccc142068357cecd332b2625' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'XUV300'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Mahindra/XUV300/10770/1701855736841/front-left-side-47.jpg?impolicy=resize&imwidth=420' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Bolero'){
        echo "<html><body><img src='https://static.autox.com/uploads/2022/10/Mahindra-Bolero-Neo-Front-Three-Quarter1.jpg' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'I20'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Hyundai/i20/9471/1694165749301/exterior-image-164.jpg?impolicy=resize&imwidth=420' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Verna'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Hyundai/Verna/9744/1694602428666/exterior-image-165.jpg?impolicy=resize&imwidth=420' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Venue'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Hyundai/Venue/7931/1626089251600/3d-model-163.jpg?impolicy=resize&imwidth=420'></body></html>";
    }
    elseif($_POST["car"] == 'Creta'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Hyundai/Creta/7695/1651645683867/front-left-side-47.jpg?impolicy=resize&imwidth=420' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Baleno'){
        echo "<html><body><img src='https://imgcdn.oto.com/large/gallery/exterior/37/2631/suzuki-baleno-front-angle-low-view-784951.jpg' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Brezza'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Maruti/Brezza/10388/1694424068944/rear-left-view-121.jpg?impolicy=resize&imwidth=420' style='height: 500px; width: 800px;'></body></html>";
    }
    elseif($_POST["car"] == 'Swift'){
        echo "<html><body><img src='https://stimg.cardekho.com/images/carexteriorimages/930x620/Maruti/Swift/10406/1697698080681/front-left-side-47.jpg?impolicy=resize&imwidth=420' style='height: 500px; width: 800px;'></body></html>";
    }
    else{
        echo "Car Not Found!";
    }
?>
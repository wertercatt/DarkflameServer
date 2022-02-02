-- Approves each players pending character name
USE darkflame; UPDATE charinfo SET name = pending_name WHERE pending_name != ""; --Set the player's name to their pending name
USE darkflame; UPDATE charinfo SET pending_name = "" WHERE pending_name != ""; --Set the player's pending name to an empty string

--Approve all pet names
USE darkflame; UPDATE pet_names SET approved=2;

--Approve all player properties
USE darkflame; UPDATE properties SET mod_approved=1;

--Set properties to public. To disable this add a hashtag before it
USE darkflame; UPDATE properties SET privacy_option=2;

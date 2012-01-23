<?php
/**
 * Sports IT Events theming
 * 
 * Available variables:
 * 
 * 
 * $data: array of sports it returned data. Each element contains:
 *    id
 *    homeTeamId
 *    awayTeamId
 *    eventType 
 *    eventDesc
 *    homeLeagueID 
 *    vistingLeagueID 
 *    homeSeasonID 
 *    vistingSeasonID 
 *    eventStart 
 *    customerID 
 *    eventEnd 
 *    firstName
 *    lastName 
 *    homeTeam 
 *    awayTeam 
 *    resourceName 
 *    subResourceName 
 *    facilityID
 *    resourceID 
 *    subResourceID 
 *    resourceAddress 
 *    resourceCity 
 *    resourceState 
 *    resourceZip 
 *    isEventPublished
 *
 */
?>
<?php
  $latDate = NULL;
?>
<div class="sportsit-events">
  <?php foreach ($data as $event):?>
    <?php $thisDate = date('l F j, Y', strtotime($event->eventStart));?>
    <?php if($thisDate != $lastDate):?>
      <?php $lastDate = $thisDate;?>
      <h3 class="event-date">
        <?php print $thisDate;?> 
      </h3>
    <?php endif;?>
    <div class="event event-type-<?php print $event->eventType;?>">
      <div class="time">
        <?php print date('G:i', strtotime($event->eventStart));?> 
        -
        <?php print date('G:i', strtotime($event->eventEnd));?> 
      </div>
      <div class="description">
        <?php print $event->eventDesc;?> 
        @
        <?php print date('G:i', strtotime($event->eventStart));?> 
        on
        <?php print $event->resourceName;?>:
        <?php print $event->subResourceName;?>
      </div>
    </div>
  <?php endforeach;?>
</div>